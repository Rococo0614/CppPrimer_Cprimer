#include <stdio.h>

int main()
{
    double c, f;
    scanf("%lf",&f );
    c = 5.0f * (f - 32.0f ) / 9.0f;
    printf("%.5f",c );
    return 0;
}