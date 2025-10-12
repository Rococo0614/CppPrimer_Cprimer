#include <stdio.h>

int main()
{
    int a1, a2, n, an, q;
    scanf("%d %d %d", &a1, &a2, &n);
    q = a2 - a1;
    an = a1 + (n - 1) * q;
    printf("%d", an);
    return 0;

}