#include <stdio.h>

typedef struct
{
    int p; // 分子
    int q; // 分母
} frac;

// Function prototype for gcd
int gcd(int a, int b);
int gcd(int a, int b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int abs(int num)
{
    return num < 0 ? -num : num;
}

frac simp(frac f);
frac simp(frac f)
{
    int k = gcd(f.p, f.q);
    int symble = f.p * f.q < 0;

    return (frac){abs(f.p / k) * (symble ? -1 : 1), abs(f.q / k)};
}

frac add(frac a, frac b)
{
    frac r;
    r.q = a.q * b.q;
    r.p = a.p * b.q + a.q * b.p;
    return simp(r);
}

frac minus(frac a, frac b);
frac minus(frac a, frac b)
{
    b.q = -b.q;
    return add(a, b);
}

frac multiply(frac a, frac b)
{
    frac r;
    r.p = a.p * b.p;
    r.q = a.q * b.q;
    return simp(r);
}

frac reciprocal(frac f);
frac reciprocal(frac f)
{
    frac r;
    r.p = f.q;
    r.q = f.p;
    return r;
}

int main()
{
    frac a, b;
    char operator;

    scanf("%d/%d %c %d/%d", &a.p, &a.q, &operator, &b.p, &b.q);

    frac res;

    switch (operator)
    {
    case '+':
        res = add(a, b);
        break;

    case '-':
        res = minus(a, b);
        break;

    case '*':
        res = multiply(a, b);
        break;

    case '/':
        res = multiply(a, reciprocal(b));
        break;
    }

    if (res.q == 1)
    {
        printf("%d/%d %c %d/%d = %d\n", a.p, a.q, operator, b.p, b.q, res.p);
    }
    else
    {
        printf("%d/%d %c %d/%d = %d/%d\n", a.p, a.q, operator, b.p, b.q, res.p, res.q);
    };

    return 0;
}
