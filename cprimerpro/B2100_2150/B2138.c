#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_largest_prime(int num){
    bool *is_composite = (bool*) calloc(num+1, sizeof(bool));
    int *Primes = (int*) malloc((num+1) * sizeof(int)), cnt = 0;
    for(int i = 2; i <= num; i++){
        if(!is_composite[i]){
            Primes[cnt++] = i;
        }
        for(int j =0; j < cnt && i * Primes[j] <= num; j++){
            is_composite[i * Primes[j]] = true;
            if(i % Primes[j] == 0) break; 
        }
    }
    for(int j = cnt-1; j >= 1; j--){
        if(num % Primes[j] == 0){
            free(is_composite);
            int result = Primes[j];
            free(Primes);
            return result;
        }
    }
}

bool is_Prime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int m, n;
    if(scanf("%d %d",&m, &n) != 2){
        return -1;
    }


    int p = 0;
    if(m < n){
        for(int i = m; i <= n; i++){
            switch(is_Prime(i)){
                case 1 : p = i ;break;
                case 0 : {
                    p = get_largest_prime(i);
                    break;
                }
            }
            if(i == n){
                printf("%d", p);
            }
            else{
                printf("%d,",p);
            }
        }
    }
    else{
        switch(is_Prime(m)){
            case 1 : printf("%d", m); break;
            case 0 : printf("%d", get_largest_prime(m));
        }
    }
    return 0;
}