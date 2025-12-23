/*
H22. 【中学】科学记数法（选做）
成绩	5	开启时间	2025年12月5日 星期五 00:05
折扣	0.8	折扣时间	2026年01月17日 星期六 23:59
允许迟交	是的	关闭时间	2026年01月17日 星期六 23:59
对于非常大或者非常小的数据，我们通常用科学记数法来表示。例如在科技文献和电脑中经常遇到的
2.3×106 （计算机中的科学记数法表示为：2.3E6），或者 9.18×10-5
（科学记树法表示：9.18E-5）这种类型的数据。

输入：
    用科学记数法表示的数据。即为符合C语言表示的科学记数法表示。

输出：
    该数据的双精度表示

说明：
    输入数据的精度不高于小数点后50位。
    输入数据时，在实数和幂之间有空格进行分隔，空格个数不定。
    结果保留到小数点后8位，如不足8位用0补足，超过8位则截断，不进行四舍五入的处理。

测试用例 1
1.2345 E 3↵

1234.50000000↵

测试用例 2
1.2345 e-3↵

0.00123450↵

测试用例 3
2.23456789123456789123456789 e 20↵

223456789123456789123.45678900↵

测试用例 4
1 E 0↵

1.00000000↵

测试用例 6
2.2345678901234567890 E 1↵

22.34567890↵


*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char line[200];

  if (fgets(line, sizeof(line), stdin) == NULL) {
    return 1;
  }

  // 去除换行符
  line[strcspn(line, "\n")] = '\0';

  // 找到E或e的位置
  char *e_pos = NULL;
  for (int i = 0; line[i]; i++) {
    if (line[i] == 'E' || line[i] == 'e') {
      e_pos = &line[i];
      break;
    }
  }

  if (e_pos == NULL) {
    // 没有E，可能不是科学记数法
    printf("Invalid input\n");
    return 1;
  }

  // 分离系数和指数
  *e_pos = '\0';
  char *coeff_str = line;
  char *exp_str = e_pos + 1;

  // 去除系数和指数的前后空格
  // 跳过系数前的空格
  while (isspace(*coeff_str))
    coeff_str++;
  // 去除系数后的空格
  char *coeff_end = coeff_str + strlen(coeff_str) - 1;
  while (coeff_end > coeff_str && isspace(*coeff_end)) {
    *coeff_end = '\0';
    coeff_end--;
  }

  // 跳过指数前的空格
  while (isspace(*exp_str))
    exp_str++;
  // 去除指数后的空格
  char *exp_end = exp_str + strlen(exp_str) - 1;
  while (exp_end > exp_str && isspace(*exp_end)) {
    *exp_end = '\0';
    exp_end--;
  }

  // 现在 coeff_str 是系数字符串，exp_str 是指数字符串
  // 解析系数，找出小数点位置
  char *dot_pos = strchr(coeff_str, '.');
  int decimal_places = 0;
  char digits[200]; // 存储不带小数点的数字
  int digits_len = 0;

  if (dot_pos != NULL) {
    // 计算小数位数
    decimal_places = strlen(dot_pos + 1);
    // 构建不带小数点的数字字符串
    for (char *p = coeff_str; *p; p++) {
      if (*p != '.') {
        digits[digits_len++] = *p;
      }
    }
  } else {
    // 没有小数点
    strcpy(digits, coeff_str);
    digits_len = strlen(digits);
  }
  digits[digits_len] = '\0';

  // 去除前导零，但保留至少一个数字（如果是全零）
  int start = 0;
  while (start < digits_len - 1 && digits[start] == '0') {
    start++;
  }
  // 移动数字到开头
  if (start > 0) {
    for (int i = start; i <= digits_len; i++) {
      digits[i - start] = digits[i];
    }
    digits_len -= start;
    // 更新小数位数（如果小数点前的零被去除了）
    // 注意：这里的小数位数指的是原系数的小数位数，不应该改变
    // 但我们需要调整 actual_exponent 吗？
    // 实际上，去掉前导零不影响小数位数，因为小数位数只计算小数点后的位数
    // 但我们需要调整，因为数字变短了
    // 例：0.00001 -> 数字"000001"，去掉前导零变成"1"，但小数位数还是5
    // actual_exponent = exponent - 5
    // 这是正确的，因为0.00001 × 10^5 = 1
  }

  // 解析指数
  int exponent = atoi(exp_str);

  // 计算实际指数：指数 - 小数位数
  int actual_exponent = exponent - decimal_places;

  // 构建结果字符串（带小数点的完整表示）
  char full_number[400];
  int full_len = 0;

  if (actual_exponent >= 0) {
    // 小数点向右移动 actual_exponent 位
    // 先复制所有数字
    strcpy(full_number, digits);
    full_len = digits_len;
    // 在末尾添加 actual_exponent 个零
    for (int i = 0; i < actual_exponent; i++) {
      full_number[full_len++] = '0';
    }
    full_number[full_len] = '\0';
    // 现在 full_number 是整数部分，需要添加小数点和8个零
    // 但我们还需要处理原系数的小数部分
    // 实际上，数字已经是整数了，小数点在末尾
  } else {
    // 小数点向左移动 -actual_exponent 位
    int shift = -actual_exponent;
    if (shift <= digits_len) {
      // 在数字内部插入小数点
      int pos = digits_len - shift;
      strncpy(full_number, digits, pos);
      full_number[pos] = '.';
      strcpy(full_number + pos + 1, digits + pos);
      full_len = digits_len + 1; // 增加了小数点
    } else {
      // 需要在前面补零
      int zeros_needed = shift - digits_len;
      full_number[0] = '0';
      full_number[1] = '.';
      for (int i = 0; i < zeros_needed; i++) {
        full_number[2 + i] = '0';
      }
      strcpy(full_number + 2 + zeros_needed, digits);
      full_len = 2 + zeros_needed + digits_len;
    }
  }

  // 现在 full_number 是带小数点的完整数字字符串
  // 需要格式化输出，保留8位小数
  // 首先找到小数点的位置
  char *dot_in_full = strchr(full_number, '.');

  if (dot_in_full == NULL) {
    // 没有小数点，是整数，需要添加小数点和8个零
    // 去除整数部分的前导零（保留至少一个数字）
    char *int_part = full_number;
    while (int_part[0] == '0' && int_part[1] != '\0') {
      int_part++;
    }
    printf("%s.00000000\n", int_part);
  } else {
    // 有小数点，需要处理小数部分
    char integer_part[400];
    char fractional_part[400];

    // 分离整数部分和小数部分
    int dot_index = dot_in_full - full_number;
    strncpy(integer_part, full_number, dot_index);
    integer_part[dot_index] = '\0';
    strcpy(fractional_part, dot_in_full + 1);

    // 去除整数部分的前导零（保留至少一个数字）
    char *int_part = integer_part;
    while (int_part[0] == '0' && int_part[1] != '\0') {
      int_part++;
    }

    int fractional_len = strlen(fractional_part);

    if (fractional_len >= 8) {
      // 小数部分长度>=8，截取前8位
      fractional_part[8] = '\0';
      printf("%s.%s\n", int_part, fractional_part);
    } else {
      // 小数部分长度<8，补零
      printf("%s.%s", int_part, fractional_part);
      for (int i = fractional_len; i < 8; i++) {
        printf("0");
      }
      printf("\n");
    }
  }

  return 0;
}
