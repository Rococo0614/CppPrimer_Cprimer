#include <stdio.h>
#include <math.h>

#define PI 3.14
#define water 20000.0

int main()
{
    int height, radius, rnum;
    scanf("%d %d", &height, &radius);
    double volume = PI * radius * radius * height;
    double num = water / volume;
    rnum = num + 1.0;
    printf("%d", rnum);
    return 0;

}

// int强转是直接截断