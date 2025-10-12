#include <stdio.h>

int main()
{
    int Infected,Death;
    scanf("%d\n%d",&Infected ,&Death );
    float DIrate =   (float) ( Death *100 ) / Infected ;
    printf("%.3f%%",DIrate );
    return 0;

}