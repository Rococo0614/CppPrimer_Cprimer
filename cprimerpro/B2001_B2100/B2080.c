#include <stdio.h>

int main()
{
    float x;
    int n;
    if(scanf("%f %d", &x, &n) != 2)
    return -1;

    double t = x;
    double sum = 1 + x;
    for(int i = 1; i < n; i++)
    {
        t *= x;
        sum += t;
    }

    printf("%.2lf", sum);
    return 0;
}