#include <stdio.h>

#define PI 3.14159
int main()
{
    double radius, diameter, full_length, size;
    scanf("%lf",&radius);
    diameter = 2.0f * radius ;
    full_length = 2.0f * PI * radius;
    size = PI * radius *radius;
    printf("%.4f %.4f %.4f", diameter, full_length, size);
    return 0;

}