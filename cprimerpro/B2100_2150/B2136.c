#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Prime{
    int *PrimeArr;
    int Primenum;
};

struct Prime get_Result(int num){
    struct Prime result = {NULL, 0};
    bool *is_promsite = (bool*) calloc(num+1, sizeof(bool));
    int *Primes = malloc(num*sizeof(int));
    int cnt = 0;
    for(int i = 2; i <= num; i++){
        if(!is_promsite[i])
        Primes[cnt++] = i;
        for(int j = 0; j < cnt && i * Primes[j] <= num; j++){
            is_promsite[i*Primes[j]] = true;
            if(i % Primes[j] == 0) break;
        }
    }    
    int *final_primes = realloc(Primes, cnt*sizeof(int));
    result.PrimeArr = final_primes;
    result.Primenum = cnt;
    free(is_promsite);
    return result;
}

void free_Prime(struct Prime *p){
    free(p->PrimeArr);
    p->PrimeArr = NULL;
    p->Primenum = 0;
}

int is_Palindrome(int num){
    int reversed = 0;
    while( num > reversed){
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return num == reversed || num == reversed / 10;

}

int main(){
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int double_count = 0;
    struct Prime result = get_Result(num);
    for(int i = 0; i <result.Primenum;i++)
    {
        if(result.PrimeArr[i] >= 11){
            if(is_Palindrome(result.PrimeArr[i])){
            double_count++;
        }
    }


    }
    printf("%d", double_count);
    free_Prime(&result);
    return 0;

}