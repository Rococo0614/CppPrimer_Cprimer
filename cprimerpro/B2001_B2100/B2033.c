#include <stdio.h>

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    a = a * b;
    printf("%ld", a);
    return 0;
}