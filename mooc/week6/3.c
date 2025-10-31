/*
题目内容：

我们寄信都要贴邮票，在邮局有一些小面值的邮票，通过这些小面值邮票中的一张或几张的组合，可以满足不同邮件的不同的邮资。
现在，邮局有4种不同面值的邮票。在每个信封上最多能贴5张邮票，面值可相同，可不同。



输入格式:

四种邮票的面值。



输出格式：

用这四种面值组成的邮资最大的从1开始的一个连续的区间。



说明：
如结果为10，则表明使用4张邮票可组合出1、2、3、4、5、6、7、8、9、10这些邮资。



名词解释：
邮资：就是你寄东西需要花多少钱。
邮票面额：是由国家发行的具有固定价格的花纸片，被称为邮票。

如果你寄东西，邮局称了重量，告诉你要240分。这样你就要贴邮票了。如果现在邮局的邮票有面值为80分、50分、20分和10分的四种，你就可以
采用不同的组合得到240的邮资，例如：采用3张80分的可以凑出240分；或者24张10分的凑起来240分也可以。显然不同邮票的组合都可以得到同样一种邮资。



输入样例：

1 4 12 21


输出样例：

The max is 71.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int stamps[4];
    scanf("%d%d%d%d", &stamps[0], &stamps[1], &stamps[2], &stamps[3]);
    int sum = 1;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i <= 5 && flag == 0; i++)
        {
            for (int j = 0; j <= 5 - i && flag == 0; j++)
            {
                for (int k = 0; k <= 5 - i - j && flag == 0; k++)
                {
                    for (int l = 0; l <= 5 - i - j - k && flag == 0; l++)
                    {
                        int current_sum = stamps[0] * i + stamps[1] * j + stamps[2] * k + stamps[3] * l;
                        if (current_sum == sum)
                        {
                            sum++;
                            flag = 1;
                        }
                    }
                }
            }
        }
        if (flag == 0)
        {
            sum -= 1;
            break;
        }
    }
    printf("The max is %d.\n", sum);
    return 0;
}
