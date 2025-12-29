/*
43/29【穷举】零钱换整钱*

[该题也是第29题]

    小明手中有硬币，小红手中有若干张10元的纸币。已知 1 角硬币厚 1.8mm，5 角硬币厚 1.5mm，1 元硬币厚 2.0mm 。小红拿出若干张10元的纸币，小明要将 1 角的硬币放成一摞，将 5 角的硬币放成一摞，将 1 元的硬币放成一摞，如果 3 摞硬币一样高，且三摞硬币的金额之和正好等于小红要求的面值，则双方交换，否则没有办法交换。

输入： 
    小红希望交换几张10元的纸币

输出：
    1 角的数量,5 角的数量,1元的数量

测试用例 1
In:
8↵

Out:
50,60,45↵

*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int target_amount = n * 10;
    
    if (target_amount % 16 != 0)
    {
        printf("No change.\n");
        return 0;
    }
    int each_height = (target_amount / 16) * 18; // mm
    int num_1_cent = each_height / 1.8;
    int num_5_cent = each_height / 1.5;
    int num_10_cent = each_height / 2.0;

    printf("%d,%d,%d\n", num_1_cent, num_5_cent, num_10_cent);
    
    return 0;
}
