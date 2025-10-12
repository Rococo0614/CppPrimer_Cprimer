#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sieve_of_euler(int n){
    bool is_composite[n + 1];
    int primes[n+1],cnt = 0;
    memset(is_composite, false, sizeof(is_composite));

    for(int i = 2; i <=n; i++)
    {
        if(!is_composite[i])
        primes[cnt++] = i;
        for(int j = 0; j < cnt && i * primes[j] <= n; j++){
            is_composite[i* primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
    printf("%d", cnt);
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    sieve_of_euler(num);
    return 0;
}