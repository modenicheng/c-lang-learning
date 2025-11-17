/*
3身份证的奥秘（10分）
题目内容：

18位身份证标准在国家质量技术监督局于1999年7月1日实施的
GB11643-1999《公民身份号码》中做了明确的规定。
GB11643-1999《公民身份号码》为GB11643-1989《社会保障号码》的修订版，其中指出将原标准名称"社会保障号码"更名为"公民身份
号码"，另外GB11643-1999《公民身份号码》从实施之日起代替GB11643-1989。GB11643-1999《公民身份号码》主要内容如
下：

一、范围
该标准规定了公民身份号码的编码对象、号码的结构和表现形式，使每个编码对象获得一个唯一的、不变的法定号码。

二、编码对象
公民身份号码的编码对象是具有中华人民共和国国籍的公民。

三、号码的结构和表示形式
1、号码的结构
公民身份号码是特征组合码，由十七位数字本体码和一位校验码组成。排列顺序从左至右依次为：六位数字地址码，八位数字出生日期码，三位数字顺序码和一位数字校验码。

2、地址码
表示编码对象常住户口所在县(市、旗、区)的行政区划代码，按GB/T2260的规定执行。

3、出生日期码
表示编码对象出生的年、月、日，按GB/T7408的规定执行，年、月、日代码之间不用分隔符。

4、顺序码
表示在同一地址码所标识的区域范围内，对同年、同月、同日出生的人编定的顺序号，顺序码的奇数分配给男性，偶数分配给女性。

5、校验码
（1）十七位数字本体码加权求和公式

S = Sum(Ai * Wi), i = 0, ... , 16 ，先对前17位数字的权求和
Ai: 表示第i位置上的身份证号码数字值
Wi: 表示第i位置上的加权因子
Wi: 7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
（2）计算模

Y = mod(S, 11)
（3）通过模得到对应的校验码

Y: 0 1 2 3 4 5 6 7 8 9 10
校验码: 1 0 X 9 8 7 6 5 4 3 2
四、举例如下：
北京市朝阳区: 11010519491231002X
广东省汕头市: 440524188001010014

15位的身份证号升级办法：

15位的身份证号：dddddd yymmdd xx p

18位的身份证号：dddddd yyyymmdd xx p y

其中dddddd为地址码（省地县三级）

yyyymmdd yymmdd 为出生年月日

xx顺号类编码

p性别

15 位的 yy 年升为 18 位后，变成 19yy年，但对于百岁以上老人， 则为 18yy 年，此时，他们的最后三位顺序码为996, 997, 998 或 999 来标记。



输入格式:

输入n组身份证号码，第一行为个数，以后每行为身份证号码。



输出格式：

如果输入的身份证号码为15位，则将其升级为18位后显示输出；否则判断其是否为合法身份证号，并逐行输出。



输入样例：

4
350622197904130331
11010519491231002X
110105491231002
110105491231996[回车]
输出样例：

Invalid[回车]
Valid[回车]
11010519491231002X[回车]
110105184912319965[回车]
*/

#include <stdio.h>
#include <string.h>

char verify_code(char *id);

void id_upgrade(char *str, char *new_id)
{
    if (strlen(str) == 18)
    {
        strcpy(new_id, str);
        return;
    }
    // Copy first 6 digits (address code)
    for (int i = 0; i < 6; i++)
    {
        new_id[i] = str[i];
    }
    // Add century digits
    new_id[6] = '1';
    if (str[12] == '9' && str[13] == '9' && (str[14] >= '6' && str[14] <= '9'))
    {
        new_id[7] = '8';
    }
    else
    {
        new_id[7] = '9';
    }
    // Copy the rest of the digits (positions 6-14 from 15-digit ID to positions 8-16 in 18-digit ID)
    for (int i = 6; i < 15; i++)
    {
        new_id[i + 2] = str[i];
    }
    // Calculate and add verification code
    new_id[17] = verify_code(new_id);
    new_id[18] = '\0';
    return;
}

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char verify_code_map[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int num(char c)
{
    return c - '0';
}

char verify_code(char *id)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        sum += (num(id[i]) * weight[i]);
    }
    return verify_code_map[sum % 11];
}

int is_all_digits(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int validate(char *id)
{
    // Check if first 17 characters are digits
    if (!is_all_digits(id, 17))
    {
        return 0;
    }
    if (verify_code(id) == id[17])
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int r = 0; r < n; r++)
    {
        char id[19] = "";
        scanf("%s", id);
        if (strlen(id) == 15)
        {
            // Check if 15-digit ID contains only digits
            if (!is_all_digits(id, 15))
            {
                printf("Invalid\n");
                continue;
            }
            char new_id[19] = "";
            id_upgrade(id, new_id);
            printf("%s\n", new_id);
            continue;
        }
        else if (strlen(id) == 18)
        {
            int is_valid = validate(id);
            if (is_valid)
            {
                printf("Valid\n");
                continue;
            }
            else
            {
                printf("Invalid\n");
                continue;
            }
        }
        else
        {
            // Handle invalid length
            printf("Invalid\n");
            continue;
        }
    }
    return 0;
}
