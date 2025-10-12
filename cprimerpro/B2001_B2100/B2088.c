#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j;
    if(scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j) != 10)
    return -1;

    double price = a * 28.9 + b * 32.7 + c * 45.6
    + d * 78 + e * 35 + f * 86.2 + g * 27.8 + h * 43
    + i * 56 + j * 65;
    printf("%.1lf", price);
    return 0;
}