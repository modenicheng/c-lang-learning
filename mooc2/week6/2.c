/**
2成绩统计（10分）
题目内容：

    有如下学生成绩表，第一列前4行为学生姓名，第一列最后一行为平均分，表中给定数据为学生成绩（每一列为同一门课）


wanglei

78

90

87

92

lihong

88

91

89

78

zhangli

84

76

83

75

liuming

88

90

71

83

AVERAGE









编程输出：学生姓名，每个学生的平均分，及各门课程平均分

输入格式：

无

输出格式：

学生姓名，每个学生的平均分（按行输出）

各门课程平均分（按列输出）

（若平均分为整数，则输出整数，若平均分为小数，则保留两位）



输入样例：

无

输出样例：

wanglei,0.00[回车]

lihong,0.50[回车]

zhangli,0.50[回车]

liuming,80[回车]

AVERAGE:4.50,6.75,2.50,2[回车]

（仅作输出格式实例展示，不代表最终结果）

时间限制：500ms内存限制：32000kb */

#include <stdio.h>
#include <math.h>

// 定义学生结构体
typedef struct {
    char name[20];
    int scores[4];
    double average;
} Student;

// 格式化输出：如果是整数输出整数，否则保留两位小数
void print_formatted(double value) {
    if (fabs(value - round(value)) < 1e-6) {
        printf("%d", (int)round(value));
    } else {
        printf("%.2f", value);
    }
}

int main() {
    // 初始化学生数据
    Student students[4] = {
        {"wanglei", {78, 90, 87, 92}, 0},
        {"lihong", {88, 91, 89, 78}, 0},
        {"zhangli", {84, 76, 83, 75}, 0},
        {"liuming", {88, 90, 71, 83}, 0}
    };

    // 计算每个学生的平均分
    for (int i = 0; i < 4; i++) {
        double sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = sum / 4.0;
    }

    // 计算每门课程的平均分
    double course_averages[4] = {0, 0, 0, 0};
    for (int j = 0; j < 4; j++) {
        double sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += students[i].scores[j];
        }
        course_averages[j] = sum / 4.0;
    }

    // 输出每个学生的姓名和平均分
    for (int i = 0; i < 4; i++) {
        printf("%s,", students[i].name);
        print_formatted(students[i].average);
        printf("\n");
    }

    // 输出各门课程平均分
    printf("AVERAGE:");
    for (int j = 0; j < 4; j++) {
        if (j > 0) {
            printf(",");
        }
        print_formatted(course_averages[j]);
    }
    printf("\n");

    return 0;
}