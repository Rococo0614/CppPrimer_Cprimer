#include <stdio.h>

int main()
{
    long long num;
    int k;
    if(scanf("%lld %d", &num, &k) != 2)
    return -1;

    int cnt = 0;
    while(num != 0)
    {
        if(num % 10 == 3)  
            cnt++;
            num = num / 10;   
    }
    if(cnt == k)
    printf("YES");
    else
    printf("NO");
    return 0;
}