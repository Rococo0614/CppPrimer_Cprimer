#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Prime{
    int *Primearr;
    int Primecnt;
};

struct Prime get_the_primes(int m){
    struct Prime result = {NULL, 0};
    bool *is_composite = (bool*) calloc(m+1, sizeof(bool));
    int *Primes = (int*) malloc((m+1)*sizeof(int)), cnt = 0;
    for(int i = 2; i <= m ; i++){
        if(!is_composite[i]){
            Primes[cnt++] = i;
        }
        for(int j = 0; j < cnt && i * Primes[j] <=m; j++){
            is_composite[i*Primes[j]] = true;
            if(i % Primes[j] == 0) break;
        }

    }
    int *final_Primes = realloc(Primes, cnt*sizeof(int));
    result.Primearr = final_Primes;
    result.Primecnt = cnt;
    free(is_composite);
    return result;
}

void free_prime(struct Prime *p){
    free(p->Primearr);
    p->Primearr = NULL;
    p->Primecnt = 0;
}

bool is_Prime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int reverse_num(int num){
    int reverse = 0;
    while(num > 0){
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}

int main(){

    int m, n;
    if(scanf("%d %d", &m, &n) != 2){
        return -1;
    }

    if(m < n){
        struct Prime result = get_the_primes(n);
        int cnt = 0;
        int *final_Prime = (int*) malloc((result.Primecnt) * sizeof(int));
        for(int i = 0; i <= result.Primecnt - 1; i++)
        {
            if(result.Primearr[i] >= m){
                final_Prime[cnt] = result.Primearr[i];
                cnt++;
            }
        }
        if(cnt == 0){
            free_prime(&result);
            free(final_Prime);
            printf("No");
            return 0;
        }
        final_Prime = realloc(final_Prime, (cnt+1)*sizeof(int));
        int flag = 0;
        int *ff_prime = (int*) malloc(cnt*sizeof(int));
        for(int i = 0; i < cnt; i++){
            if(is_Prime(final_Prime[i]) && is_Prime(reverse_num(final_Prime[i]))){
                ff_prime[flag] = final_Prime[i];
                flag++;
            }
        }
        if(flag == 0){
            free_prime(&result);
            free(ff_prime);
            free(final_Prime);
            printf("No");
            return 0;
        }
        ff_prime = realloc(ff_prime, (flag+1)*sizeof(int));
        free(final_Prime);
        for(int i = 0; i < flag; i++){
            printf("%d", ff_prime[i]);
            if(i != flag - 1){
                printf(",");
            }
        }
        free(ff_prime);
        free_prime(&result);
    }

    else{
        if(is_Prime(m) && is_Prime(reverse_num(m))){
            printf("%d",m);
            return 0;
        }
        else{
            printf("No");
            return 0;
        }    
    }

    
}