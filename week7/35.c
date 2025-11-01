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
#include <stdlib.h>
#include <string.h>

char rank[15] = {'2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};
char suit[4] = {'C', 'D', 'S', 'H'};

typedef struct
{
    int rank; // 2-10, J = 11, Q = 12, K = 13, A = 14
    int suit; // Heart = 45, Spade = 30, Diamond = 15, Club = 0
    // 类似进位制，保证 rank + suit 不会重复。（如果 suit 从 1-4, 会出现 CA = DK 的情况，无法排序）
} Card;

int weight(Card card)
{
    return card.rank + card.suit;
}

void print_card(Card card)
{
    if (card.rank == 10)
    {
        printf("%c10", suit[(card.suit / 15)]);
        return;
    }
    printf("%c%c", suit[(card.suit / 15)], rank[card.rank - 2]);
}

void sort_cards(Card cards[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (weight(cards[j]) < weight(cards[j + 1]))
            {
                Card tmp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = tmp;
            }
        }
    }
}

Card get_card()
{
    Card card;

    int rank = 0;
    int suit;
    while (1)
    {
        char c = getchar();
        if (c == ' ' || c == '\n')
        {
            card = (Card){rank, suit};
            return card;
        }
        else if (c >= '0' && c <= '9')
        {
            rank *= 10;
            rank += c - 48;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            switch (c)
            {
            case 'A':
                rank = 14;
                break;
            case 'K':
                rank = 13;
                break;
            case 'Q':
                rank = 12;
                break;
            case 'J':
                rank = 11;
                break;
            case 'H':
                suit = 45;
                break;
            case 'S':
                suit = 30;
                break;
            case 'D':
                suit = 15;
                break;
            case 'C':
                suit = 0;
                break;
            default:
                printf("Input Error!\n");
                exit(1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Card A[3], B[3];

    for (int i = 0; i < 3; i++)
    {
        A[i] = get_card();
    }
    for (int i = 0; i < 3; i++)
    {
        B[i] = get_card();
    }

    // validation 检查牌是否唯一
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (weight(A[i]) == weight(A[j]) ||
                weight(B[i]) == weight(B[j]))
            {
                printf("Input Error!\n");
                exit(1);
            }
        }
    }
    sort_cards(A);
    sort_cards(B);

    char winner = 'X';
    for (int i = 0; i < 3; i++)
    {
        if (weight(A[i]) > weight(B[i]))
        {
            winner = 'A';
            break;
        }
        else if (weight(A[i]) < weight(B[i]))
        {
            winner = 'B';
            break;
        }
    }

    printf("Winner is %c!\n", winner);
    printf("A: ");
    for (int i = 0; i < 3; i++)
    {
        print_card(A[i]);
        if (i != 2)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    printf("B: ");
    for (int i = 0; i < 3; i++)
    {
        print_card(B[i]);
        if (i != 2)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
