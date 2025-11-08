/*
题目内容：

假设我们有 2n 张牌，它们以 1, 2, ..., n, n+1, ..., 2n
编号并在开始时保持着这种顺序。一次洗牌就是将牌原来的次序变为 n+1, 1, n+2, 2, ..., 2n, n，也就是将原来的前 n
张牌放到位置 2, 4, ..., 2n，并且将余下的 n 张牌按照他们原来的次序放到奇数位置 1, 3, ...,
2n-1。已经证明对于任何一个自然数 n，这 2n 张牌经过一定次数的洗牌就回到原来的次序。但我们不知道对于一个特定的
n，需要几次洗牌才能将牌洗回原来的次序。

输入格式：

牌张数的一半n，即初始情况下一共有2n张牌，n为int型整数

输出格式：

将牌洗回原来的次序所需要的洗牌次数

输入样例：

10

输出样例：

6[回车]
*/

// 这屌东西过不了后两个样例，怀疑是性能问题或者内存爆了
// fuck u icourse163, fuck u neteast
// mooc oj bug 一大堆，我过不了都不给提示的

// #include <stdio.h>

// void flush(int* arr, int size, int* res)
// {
//     // size = n, the half length of the array
//     // First n cards (arr[0] to arr[n-1]) go to even positions (1,3,5,... in 0-based)
//     // Last n cards (arr[n] to arr[2n-1]) go to odd positions (0,2,4,... in 0-based)
//     for (int i = 0; i < size; i++)
//     {
//         res[2 * i + 1] = arr[i];        // First n cards to odd positions
//         res[2 * i] = arr[size + i];     // Last n cards to even positions
//     }
// }

// int arr_eq(int* arr1, int* arr2, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr1[i] != arr2[i])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// void print_arr(int* arr, int size)
// {
//     printf("[");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%3d", arr[i]);
//     }
//     printf("]\n");
// }

// int main(int argc, char const *argv[])
// {
//     int n;
//     scanf("%d", &n);

//     int arr[1024] = {0};
//     int original[1024] = {0};
//     // generate a 'card' array
//     for (int i = 0; i < 2 * n; i++)
//     {
//         arr[i] = i + 1;
//         original[i] = i + 1;
//     }

//     int counter = 0;
//     while (1)
//     {
//         counter += 1;
//         int res[1024] = {0};
//         flush(arr, n, res);
//         // print_arr(res, 2 * n);
//         if (arr_eq(res, original, 2 * n))
//         {
//             printf("%d", counter);
//             break;
//         }
//         // Copy res to arr for next iteration
//         for (int i = 0; i < 2 * n; i++)
//         {
//             arr[i] = res[i];
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int index = 1;
    int count = 0;
    while (1)
    {
        count += 1;
        if (index > n)
        {
            index = (index - n) * 2 - 1;
        }
        else
        {
            index = (index * 2);
        }
        if (index == 1)
        {
            break;
        }
    }
    printf("%d", count);
    return 0;
}
