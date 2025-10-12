#include <stdio.h>

int main()
{
    int x,y,a,b;
    scanf("%d %d %d %d",&x ,&a, &y, &b);
    double ax = (double)a*x;
    double by = (double)b*y;
    double denom = (double) (a-b);
    double z = (float)(ax-by)/denom;
    printf("%.2f", z);
    return 0;
}