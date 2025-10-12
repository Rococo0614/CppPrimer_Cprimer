#include <stdio.h>

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    return -1;

    int cnt = 0;
    for(int i = 2;; i++)
    {
        int flag = 1;
        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cnt++;
            if(cnt == n)
            {
                printf("%d", i);
                break;
            }
        }
    }

    return 0;
}