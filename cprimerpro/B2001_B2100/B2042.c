#include <stdio.h>

int main()
{
    long int num;
    scanf("%ld", &num);
    if(num % 3 == 0)
    {
        if(num % 5 == 0 )
        printf("YES");
        else
        printf("NO");
    }
    else
    printf("NO");
}