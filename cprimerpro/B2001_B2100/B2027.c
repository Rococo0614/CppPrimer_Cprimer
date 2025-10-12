#include <stdio.h>

#define PI 3.14

int main()
{
    double radius;
    scanf("%lf", &radius);
    double size = (4.0 / 3.0) * PI * radius * radius * radius;
    printf("%.5lf", size);
    return 0;
}