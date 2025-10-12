#include <stdio.h>

int main()
{
    long long N;
    if(scanf("%lld",&N) != 1)
    return -1;

    while(N != 1)
    {
        if(N % 2 == 0)
        {
            N = N / 2;
            printf("%lld/2=%lld\n",N*2,N);
        }
        else if(N % 2 == 1)
        {
            printf("%lld*3+1=%lld\n",N,N*3+1);
            N = N * 3 + 1;
        }
    }
    printf("End");
    return 0;
}