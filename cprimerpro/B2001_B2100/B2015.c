#include <stdio.h>

int main()
{
    double res1, res2, resf;
    scanf("%lf %lf", &res1, &res2);
    resf = 1.0f / (( 1.0f / res1 ) + ( 1.0f / res2 ));
    printf("%.2lf", resf);  
    return 0;

}