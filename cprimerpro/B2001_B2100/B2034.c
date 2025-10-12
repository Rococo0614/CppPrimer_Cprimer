#include <stdio.h>


int main()
{
    int n;
    long int a = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    a = a * 2;
    printf("%ld", a);
    return 0;

}