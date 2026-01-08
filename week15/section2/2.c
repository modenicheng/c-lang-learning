/*
输出数字

输入n个正整数，按照数字出现的顺序输出其中出现次数大于k的数字。


输入：

第一行为整数n和k，第二行为n个数字。


输出：

按照数字出现的顺序输出其中出现次数大于k的数字，如果没有满足条件的数字，
输出 `No such element.`

        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
8 2↵
1 1 2 3 2 2 1 4↵
以文本方式显示
1↵
2↵
1秒	64M	0
测试用例 3	以文本方式显示
9 7↵
2 2 2 2 2 2 2 2 4↵
以文本方式显示
2↵
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 1000000  // 假设数字最大值为1000000

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];  // 存储输入的数字
    int count[MAX_NUM + 1] = {0};  // 计数数组，初始化为0

    // 读取数字并统计
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    int found = 0;  // 标记是否找到满足条件的数字

    // 按照输入顺序输出满足条件的数字
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (count[num] > k) {
            printf("%d\n", num);
            count[num] = 0;  // 避免重复输出
            found = 1;
        }
    }

    if (!found) {
        printf("No such element.\n");
    }

    return 0;
}