/*
66. 【大学】求表示方法
成绩	10	开启时间	2025年12月5日 星期五 00:05
折扣	0.8	折扣时间	2025年12月22日 星期一 23:59
允许迟交	否	关闭时间	2025年12月29日 星期一 23:59
设 m、n 均为大于 0 的整数，m 可表示为一些不超过 n 的整数之和，f(m,n)
为这种表示方式的数目。

例如，f(5,3)=5，有 5 种表示方法：3+2，3+1+1，2+2+1，2+1+1+1，1+1+1+1+1。

请编写程序，计算 f(m,n) 的值。

输入：
         m n

输出：
         f(m,n)的值

        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1
5 3↵

5↵
1秒	64M	0
测试用例 2
6 4↵

9↵
1秒	64M	0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // dp[i] = number of ways to represent i using numbers <= current j
    unsigned long long *dp = (unsigned long long*)calloc(m + 1, sizeof(unsigned long long));
    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    dp[0] = 1;  // empty sum

    for (int j = 1; j <= n; j++) {
        for (int i = j; i <= m; i++) {
            dp[i] += dp[i - j];
        }
    }

    printf("%llu\n", dp[m]);

    free(dp);
    return 0;
}