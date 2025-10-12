#include <stdio.h>

int main()
{
    int a,b,c;
    if(scanf("%d %d %d", &a, &b, &c) != 3)
    return -1;

    int cnt = 0;
    for(int x = 0; x <= c / a; x++)
    {
        for(int y = 0; y <= c / b; y++)
        {
            if (a * x + b * y == c)
            cnt ++;
        }

    }
    printf("%d", cnt);
    return 0;
}