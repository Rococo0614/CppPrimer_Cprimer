#include <stdio.h>
#include <math.h>

int main()
{
    float n;
    scanf("%f", &n);
    n = fabs(n);
    printf("%.2f", n);
    return 0;
}