#include <stdio.h>

int main()
{
    double height;
    if(scanf("%lf", &height) != 1)
    return -1;

    double sum_height = height;

    for(int i = 0; i < 9; i++)
    {
        height = height / 2.0;
        sum_height += height * 2;  
    }

    printf("%g\n%g", sum_height, height / 2);
    return 0;
}