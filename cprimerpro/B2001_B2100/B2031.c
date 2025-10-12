#include <stdio.h>
#include <math.h>

int main()
{
    double x[3], y[3];
    double lx[2], ly[2], area;
    for(int i = 0; i < 3; i++)
    scanf("%lf %lf", &x[i], &y[i]);
    for(int i = 0; i < 2; i++)
    {
        lx[i] = x[i + 1] - x[0];
        ly[i] = y[i + 1] - y[0];
    }
    area = 0.5 * fabs(lx[0] * ly[1] - lx[1] * ly[0]);
    printf("%.2lf", area);
    
    
}