#include <stdio.h>

double abs(double num)
{
    return num < 0 ? -num : num;
}

int main()
{
    int h, m;
    scanf("%d%d", &h, &m);
    double h_degree = 30 * h + 0.5 * m;
    double m_degree = 6 * m;
    double d = abs(h_degree - m_degree);
    printf("At %d:%.2d the angle is %.1f degrees.\n", h, m, d > 180 ? d - 180 : d);
    return 0;
}