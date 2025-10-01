#include <stdio.h>

float abs(float num)
{
    return num < 0 ? -num : num;
}

int main()
{
    int h, m;
    scanf("%d%d", &h, &m);
    float h_degree = 360.0 / 12 * h;
    while (h_degree >= 360)
    {
        h_degree -= 360;
    }
    float m_degree = 360.0 / 60 * m;
    while (m_degree >= 360) {
        m_degree -= 360;
    }
    float d = abs(h_degree - m_degree);
    printf("At %.2d:%.2d the angle is %.1f degrees.\n", h, m, d > 180 ? d - 180 : d);
    return 0;
}