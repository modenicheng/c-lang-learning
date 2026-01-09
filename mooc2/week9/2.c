/**
2字符串的输入与反向显示（15分）
题目内容：

    请用标准设备文件的方式完成字符串的输入与反向显示。

输入格式：

    字符串

输出格式：

    字符串

输入样例：

abc[回车]

输出样例：

cba[回车]

时间限制：500ms内存限制：32000kb */
#include <stdio.h>
#include <string.h>

int main() {
    char input[1001];  // 缓冲区足够大
    // 从标准输入读取字符串
    fgets(input, sizeof(input), stdin);

    // 移除末尾的换行符
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // 反向输出字符串
    for (int i = len - 1; i >= 0; i--) {
        putchar(input[i]);
    }
    // 输出换行符以匹配样例格式
    putchar('\n');

    return 0;
}
