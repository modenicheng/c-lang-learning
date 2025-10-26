#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t len; // 长度，已用部分
    size_t cap; // 总容量
} vec;

void vec_init(vec *v)
{
    v->data = NULL;
    v->len = v->cap = 0;
}

void vec_free(vec *v)
{
    free(v->data);
    v->data = NULL;
    v->len = v->cap = 0;
}

static void vec_ensure(vec *v, size_t need)
{
    if (need <= v->cap)
        return;
    size_t newcap = v->cap ? v->cap * 2 : 4;

    while (newcap < need)
        newcap *= 2;
    int *p = realloc(v->data, newcap * sizeof *p);

    if (!p)
    {
        perror("realloc");
        exit(1);
    }
    v->data = p;
    v->cap = newcap;
}

void vec_push(vec *v, int x)
{
    vec_ensure(v, v->len + 1);
    v->data[v->len++] = x;
}

void vec_pop(vec *v, size_t index)
{
    for (size_t i = index; i < v->len - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    v->len -= 1;

    // Optional: shrink capacity if vector becomes too small
    // This prevents memory waste when many elements are removed
    if (v->cap > 16 && v->len < v->cap / 4)
    {
        size_t newcap = v->cap / 2;
        int *p = realloc(v->data, newcap * sizeof *p);
        if (p)
        {
            v->data = p;
            v->cap = newcap;
        }
        // If realloc fails, we continue with current capacity
    }
}

int main()
{
    int range;
    scanf("%d", &range);

    vec v;
    vec_init(&v);

    // 使用试除法生成素数：从 2 开始到 range（包含）
    for (int i = 2; i <= range; i++)
    {
        int is_prime = 1;
        // 只用已知素数试除，并在 p*p > i 时停止
        for (size_t j = 0; j < v.len; j++)
        {
            int p = v.data[j];
            if ((long long)p * p > i)
                break;
            if (i % p == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
            vec_push(&v, i);
    }

    if (v.len > 0)
        printf("The max prime number is %d.\n", v.data[v.len - 1]);
    else
        printf("No prime found up to %d.\n", range);

    vec_free(&v);
    return 0;
}
