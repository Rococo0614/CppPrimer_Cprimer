#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Prime{
    int *primearr;
    int primenum;
};

struct Prime sive_of_eula(int n){
    struct Prime result = {NULL , 0};
    if(n < 2) return result;
    bool *is_composite = (bool*) calloc(n+1, sizeof(bool));
    int cnt = 0;
    int *primes = malloc(n * sizeof(int));
    for(int i = 2; i <=n; i++){
        if(!is_composite[i]){
            primes[cnt++] = i;
        }
        for(int j = 0; j < cnt && primes[j] * i <= n; j++){
            is_composite[i*primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }

    int *final_primes = realloc(primes, cnt*sizeof(int));
    result.primearr = primes;
    result.primenum = cnt;
    free(is_composite);

    return result;
}

void free_prime(struct Prime *p){
    free(p->primearr);
    p->primearr = NULL;
    p->primenum = 0;
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;
    int flag = 0;
    struct Prime result = sive_of_eula(num);
    for(int i = 0; i < result.primenum; i++)
    {
        if(result.primearr[i+1] - result.primearr[i] == 2)
        {
            printf("%d %d\n", result.primearr[i], result.primearr[i+1]);
            flag = 1;
        }
    }
    if(!flag) printf("empty");
    
    free_prime(&result);
    return 0;
}