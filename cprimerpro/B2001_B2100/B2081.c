#include <stdio.h>

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    return -1;

    int sum= 0,nsum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 7 != 0 && i % 10 != 7 && i / 10 != 7)
        nsum += i * i;

    }

    printf("%d", nsum);
    return 0;
}