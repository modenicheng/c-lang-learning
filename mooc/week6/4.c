/*
4火锅火锅和火锅（10分）
题目内容：

众所周知，沫沫以火锅为生。在E8的聚餐活动中，他经常卖萌卖无辜领着大家吃火锅。。

有一天，沫沫听说学校附近的哺呷哺呷在某现充的赞助下有一个优惠活动，只需30软妹币，对每个客人，它会上N道菜，但是客人只能挑选其中连续上的一些菜。

于是他非常兴奋的拉着灰灰和渣渣去吃火锅去啦。

沫沫是一个十分挑食的人，所以他对每一道菜都有一个愉快度（当然因为他的挑食，某些事物的愉快度会是负数）。

为了让沫沫能非常愉快的享受这次聚餐，善解人意的灰灰和渣渣决定帮他计算，他们应该怎么选择菜才能使沫沫最开心地吃完这次聚餐。

输入格式:
第一行是一个整数T，（T <= 10）表示测试案例的个数
对于每个测试案例，第一行是一个整数N，( 1<=N <= 10000)表示菜的个数
接下来的N个数字，第i个数字si表示沫沫对第i道菜的愉快度。（ -1000 <=si <= 1000）

PS:由于CF又被血虐掉rating，所以沫沫的起始愉快度是0

PPS:沫沫完全可能得到一个为负值的愉快值， poor 沫沫。。



输出格式：
对于每个样例，输出一个数字，表示沫沫吃完之后愉快度的最大值。



HINT：

对于 5

6 -1 5 4 -7

我们选择6， -1， 5， 4这四道菜（注意必须是连续的，所以不能跳过-1）



做完后请思考,如果N的范围是1<=N<=100000呢？



输入样例：
2
5
6 -1 5 4 -7
7
0 6 -1 1 -6 7 -5

输出样例：
14
7
*/
#include <stdio.h>

int main()
{
    int round_num = 0;
    scanf("%d", &round_num);

    for (int round = 0; round < round_num; round++)
    {
        int dishes_num = 0;
        scanf("%d", &dishes_num);

        int joyment[10000];
        
        // 读取每道菜的愉快度
        for (int index = 0; index < dishes_num; index++) {
            scanf("%d", &joyment[index]);
        }

        // 使用Kadane算法求最大子数组和
        int max_sum = joyment[0];
        int current_sum = joyment[0];

        for (int i = 1; i < dishes_num; i++)
        {
            // 如果当前累加和小于0，则重新开始计算
            current_sum = (current_sum > 0) ? current_sum + joyment[i] : joyment[i];
            // 更新最大值
            max_sum = (max_sum > current_sum) ? max_sum : current_sum;
        }
        printf("%d\n", max_sum);
    }
    return 0;
}