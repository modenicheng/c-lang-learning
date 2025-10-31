/*
35【游戏】（BOSS）Poker time!

背景：两个人每人发3张牌（各从一副牌中），每张牌包括花色（红桃(Heart)>黑桃(Spade)>方块(Diamond)>梅花(Club））
和大小（从小到大依次是：2-10、J、Q、K、A），谁手上有最大的一张或多张（如果有相同的牌）牌谁获胜。

输入：A的3张牌（未排序）和B的3张牌（未排序）。（参见用例）
输出：A的3张牌的排序后的输出和B的3张牌的排序后的输出，以及A和B谁获胜。（参见用例）

测试用例 1
In:
DA H2 C3
H4 H3 DJ

Out:
Winner is B!
A: H2 DA C3
B: H4 H3 DJ

测试用例 3
In:
HA CA CB
HQ CJ CQ

Out:
Input Error!

测试用例 4
In:
HA CA CJ
DA DK DK

Out:
Input Error!

测试用例 5
In:
SA SJ SK
SA SJ SK

Out:
Winner is X!
A: SA SK SJ
B: SA SK SJ
*/

#include <stdio.h>

char rank[15] = {'2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};
char suit[4] = {'C', 'D', 'S', 'H'};

typedef struct
{
    int rank; // 2-10, J, Q, K, A
    int suit; // Heart, Spade, Diamond, Club
} Card;


void print_card(Card card)
{
    printf("%c%c", rank[card.rank - 2], suit[card.suit]);
}

Card sort_cards(Card cards[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (cards[j].rank > cards[j + 1].rank)
            {
                Card temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Card A[3], B[3];
    return 0;
}
