#include <stdio.h>

int main()
{
    int a,b;
    if(scanf("%d %d", &a, &b) != 2)
    return -1;

    long long num = 1;
    for(int i = 0; i < b; i++)
    {
        num *= a ;
        num = num % 1000;
    }

    int res = num;
    if(res >= 100)
    printf("%d", res);
    else if(res >= 10 && res < 100)
    printf("0%d", res);
    else
    printf("00%d",res);
    return 0;
}