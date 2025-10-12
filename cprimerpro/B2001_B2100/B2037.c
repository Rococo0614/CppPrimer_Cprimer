#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    n = n % 2;
    if(n == 0)
    printf("even");
    else
    printf("odd");
    return 0;
}