#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    // if (argc != 3) {
    //     fprintf(stderr, "用法: %s <ip> <port>\n", argv[0]);
    //     return 1;
    // }

    const char *ip   = "8.152.97.10";
    uint16_t    port = (uint16_t)10000;

    /* 1. 待 POST 的字符串（可换成任意内容） */
    const char *body = "123";

    /* 2. 构造最简 HTTP 请求 */
    char req[2048];
    int  len = snprintf(req, sizeof(req),
        "POST / HTTP/1.1\r\n"
        "Host: %s:%d\r\n"
        "Content-Type: text/plain; charset=utf-8\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s", ip, port, strlen(body), body);

    /* 3. 创建 TCP socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    /* 4. 填充地址结构 */
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);
    if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
        fprintf(stderr, "IP 地址格式错误\n");
        close(sock);
        return 1;
    }

    /* 5. 连接 */
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    /* 6. 发送请求 */
    if (send(sock, req, len, 0) != len) {
        perror("send");
        close(sock);
        return 1;
    }
    printf("已发送 %d 字节\n", len);

    /* 7. 简单收一行应答 */
    char resp[BUF_SIZE];
    int  n = recv(sock, resp, sizeof(resp) - 1, 0);
    if (n > 0) {
        resp[n] = 0;
        printf("服务器返回：\n%.100s...\n", resp);   /* 只打前 100 字符 */
    }

    close(sock);
    return 0;
}