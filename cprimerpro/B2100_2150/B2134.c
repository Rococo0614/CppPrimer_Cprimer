#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Prime{
    int *PrimeArr;
    int PrimeNum;
};

struct Prime get_prime_eula(int n){
    struct Prime result = {NULL, 0};
    bool *is_composite = (bool*) calloc(n+1, sizeof(bool));
    int *Primes =(int*) malloc((n+1)*sizeof(int)), cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!is_composite[i])
        Primes[cnt++] = i;
        for(int j = 0; j < cnt && i*Primes[j] <= n; j++){
            is_composite[i*Primes[j]] = true;
            if(i % Primes[j] == 0) break;
        }
    } 
    int *final_Primes = realloc(Primes, cnt*sizeof(int));
    result.PrimeArr = final_Primes;
    result.PrimeNum = cnt;
    free(is_composite);
    return result;
}

void free_Prime(struct Prime *p)
{
    free(p->PrimeArr);
    p->PrimeArr = NULL;
    p->PrimeNum = 0;
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;
    struct Prime result = get_prime_eula(num);
    int start = 0, end = result.PrimeNum - 1;
    int calcsum = -1;
    while(start <= end)
    {
        int sum = result.PrimeArr[start] + result.PrimeArr[end];
        if(sum == num){
            int calcsum1 = result.PrimeArr[start] * result.PrimeArr[end];
            if(calcsum1 > calcsum){
                calcsum = calcsum1;
            }
            start++;
            end--;
        }
        else if(sum < num)
        start++;
        else
        end--;
    }
    printf("%d", calcsum);
    free_Prime(&result);
    return 0;
}