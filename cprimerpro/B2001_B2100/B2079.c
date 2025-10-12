#include <stdio.h>

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    return -1;

    double e = 1.0, k = 1.0;
    for(int i = 1; i <= n; i++)
    {
        k *= (double)i;
        e += 1 / k;
    }

    printf("%.10lf", e);
    return 0;
}