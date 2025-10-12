#include <stdio.h>

int main()
{
    int L,R;
    if(scanf("%d %d", &L, &R) != 2)
    return -1;

    int cnt = 0;
    for(int i = L; i <= R; i++)
    {
        int num = i;
        while(num != 0)
        {
            if(num % 10 == 2)
            cnt++;
            num /= 10;
        }
    }

    printf("%d", cnt);
    return 0;
}