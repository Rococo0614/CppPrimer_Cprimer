#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_prime(int num){
    if(num < 2) return false;
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int sive_of_eula(int num){
    if(num < 2){
        return 0;
    }
    bool *is_composite = (bool*) calloc(num+1, sizeof(bool));
    int *Prime = (int*) malloc((num+1)*sizeof(int));
    int cnt = 0;
    for(int i = 2; i <= num; i++){
        if(!is_composite[i])
        Prime[cnt++] = i;
        for(int j = 0; j < cnt && i * Prime[j] <= num ; j++){
            is_composite[i*Prime[j]] = true;
            if(i % Prime[j] == 0) break;
        }
    }
    free(is_composite);
    free(Prime);
    return cnt;
}

int main(){
    int x,y;
    if(scanf("%d %d", &x, &y) != 2){
        return -1;
    }
    if(x < y){
    printf("%d", sive_of_eula(y)-sive_of_eula(x) + (int) is_prime(x));
    }
    else if(x == y){
        if(is_prime(x)){
            printf("1");
        }
        else{
            printf("0");
        }

    }
    else{
        printf("%d", sive_of_eula(x) - sive_of_eula(y) + (int) is_prime(y));
    }
    
    return 0;
}