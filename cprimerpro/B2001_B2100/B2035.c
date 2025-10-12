#include <stdio.h>

int main()
{
    long int a;
    scanf("%ld", &a);
    if(a > 0)
    printf("positive");
    else if(a < 0)
    printf("negative");
    else
    printf("zero");
    return 0;
}