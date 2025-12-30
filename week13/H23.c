/*
H23：编码（选作）
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月17日 星期六 23:59
允许迟交	是的	关闭时间	2026年01月17日 星期六 23:59

描述
为了最大程度地节约存储空间，经常需要把信息进行编码。一种很有效的编码方法是用数字来表示一串字符。
假设这些字符串都是由不重复的英文小写字母组成的，且每个字符串中的英文字母都是从小到大排列的。

这个编码系统按照如下的方式工作：

字符串是按照长度从小到大的顺序排列的
长度相同的字符串，是按照字典需排列的
则根据这个编码系统，所有的字符串从 a 开始可以编码如下：

a - 1 b - 2 ... z - 26 ab - 27 ... az - 51 bc - 52 ... vwxyz - 83681 ...
那么，请编程计算出一个字符串在这个编码系统下编码后的值是多少。

输入
输入的第一行为 N，表示有 N 组数据。后面的 N 行每行包含一个不超过 10
个字母的字符串。

输出
输出字符串所对应的编码，如果该字符串不能被编码，则输出 0。

测试用例 1
1↵
bf↵

55↵
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Precompute binomial coefficients C(n, k) for n up to 26, k up to 10
static int64_t comb[27][11];

static void init_comb() {
    // Initialize using Pascal's triangle
    for (int n = 0; n <= 26; n++) {
        comb[n][0] = 1;
        for (int k = 1; k <= 10; k++) {
            if (k > n) {
                comb[n][k] = 0;
            } else if (n == 0) {
                comb[n][k] = 0;
            } else {
                comb[n][k] = comb[n-1][k-1] + comb[n-1][k];
            }
        }
    }
}

// Compute rank of a valid string (already validated as sorted distinct lowercase letters)
// Returns rank starting from 1 (a=1). Returns 0 if invalid.
static int64_t encode(const char *s) {
    int len = 0;
    int letters[10]; // store letter indices 0..25

    // Convert to indices and compute length
    for (len = 0; s[len] != '\0' && s[len] != '\n'; len++) {
        if (len >= 10) return 0; // too long
        letters[len] = s[len] - 'a';
    }

    // Validate letters are strictly increasing
    for (int i = 0; i < len; i++) {
        if (letters[i] < 0 || letters[i] >= 26) return 0;
        if (i > 0 && letters[i] <= letters[i-1]) return 0;
    }

    // Compute total strings of length < len
    int64_t rank = 1; // start counting from 1
    for (int L = 1; L < len; L++) {
        rank += comb[26][L];
    }

    // Compute rank within strings of same length
    int prev = -1;
    for (int i = 0; i < len; i++) {
        int ci = letters[i];
        // For each possible smaller letter at this position
        for (int x = prev + 1; x < ci; x++) {
            rank += comb[26 - x - 1][len - i - 1];
        }
        prev = ci;
    }

    return rank;
}

// Read a line, handling lines longer than buffer
// Returns 1 if line was read successfully, 0 on EOF
static int read_line(char *buf, int size) {
    if (fgets(buf, size, stdin) == NULL) {
        return 0;
    }

    // Check if we got a complete line (ends with newline)
    int len = 0;
    while (len < size && buf[len] != '\0') {
        if (buf[len] == '\n') {
            // Complete line
            buf[len] = '\0';
            return 1;
        }
        len++;
    }

    // Line was too long, flush remaining characters
    if (len == size - 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // flush
        }
    }

    // Ensure null termination
    if (len < size) {
        buf[len] = '\0';
    } else {
        buf[size - 1] = '\0';
    }

    return 1;
}

int main() {
    init_comb();

    // Read N using original robust method
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            n = n * 10 + (c - '0');
        }
    }

    char line[12]; // up to 10 letters + newline + null
    for (int i = 0; i < n; i++) {
        if (!read_line(line, sizeof(line))) {
            printf("0\n");
            continue;
        }

        int64_t res = encode(line);
        printf("%" PRId64 "\n", res);
    }

    return 0;
}