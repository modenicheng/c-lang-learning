/*
调试程序练习题二
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
下面函数的功能是将已经排好序的 N 个字符串合并并输出。
函数combn的功能是采用递归算法将字符串a合并到字符串b，合并后的字符串仍保持升序排列，而且相同的字符在b字符串中只保存一个。
程序中存在着错误，请调试改错。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void combn(char *a, char *b) // 将a字符串的第一个字符插入b字符串
{ // a:待合并的字符串的首地址，b:合并后的字符串的首地址
    // 递归基：如果a是空字符串，直接返回
    if (a[0] == '\0') {
        return;
    }

    int j = 0;
    // 找到b字符串中第一个不小于a[0]的字符b[j]
    while (b[j] != '\0' && a[0] > b[j]) {
        j++;
    }

    // 如果a[0]等于b[j]，说明字符已存在，跳过插入
    if (b[j] == a[0]) {
        // 字符已存在，递归处理a的下一个字符
        combn(&a[1], b);
        return;
    }

    // 此时要么b[j]是结束符，要么a[0] < b[j]
    if (b[j] == '\0') { // 如果b[j]是字符串结束标志
        // 将字符a[0]插在b字符串的串尾
        b[j] = a[0];
        b[j + 1] = '\0';
    } else { // a[0] < b[j]，将字符a[0]插入原b[j]处
        int k = j;
        // 找到原b字符串尾
        while (b[k] != '\0') {
            k++;
        }
        // b[j]及后面的所有字符后移一个位置
        while (k >= j) {
            b[k + 1] = b[k];
            k--;
        }
        b[j] = a[0]; // 将a[0]插在b[j]处
    }

    // 递归调用combn函数，插入a字符串的下一个字符
    combn(&a[1], b);
}

int main() {
    int i, n;
    char sa[100], sc[1000] = {'\0'}; // sa保存新输入的字符串，sc保存合并后的字符串
    // printf("Number of strings n:");
    scanf("%d", &n); // 输入待合并的字符串的个数
    getchar(); // 消耗scanf留下的换行符

    for (i = 0; i < n; i++) {
        fgets(sa, sizeof(sa), stdin); // 读入一个字符串（安全版本）
        // 去掉末尾的换行符
        size_t len = strlen(sa);
        if (len > 0 && sa[len - 1] == '\n') {
            sa[len - 1] = '\0';
        }
        combn(sa, sc); // 将字符串sa合并到字符串sc中
    }
    printf("%s\n", sc); // 输出合并后的字符串
    return 0;
}