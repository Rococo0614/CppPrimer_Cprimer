#include <stdio.h>
#include <math.h>

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    a = fmod(a, b);
    printf("%g", a);
    return 0;
}