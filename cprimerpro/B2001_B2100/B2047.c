#include <stdio.h>

int main()
{
    double x, y;
    scanf("%lf", &x);
    if(x >= 0 && x < 5)
    y = -1.0 * x + 2.5;
    else if(x >= 5 && x < 10 )
    y = 2.0 - 1.5 * (x - 3.0) * (x - 3.0);
    else
    y = x / 2.0 - 1.5;
    printf("%.3lf", y);
    return 0;

}