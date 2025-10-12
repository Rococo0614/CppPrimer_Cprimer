#include <stdio.h>
#include <stdlib.h>
#include <string.h>



long long dec2new(long long num,int k){
    int new_num = 0,shu = 1;
    while(num > 0){
        new_num += (num % 10)*shu;
        shu *= k;
        num /= 10;
    }
    return new_num;
}

int max_wei1(long long num){
    int cnt = 0, max_wei = 0;
    while(num > 0){
        if(num % 10 > max_wei){
            max_wei = num % 10;
        }
        cnt++;
        num /= 10;
    }
    return max_wei;
}

int max_num(long long num1, long long num2, long long num3){
    int max_num = (num1 > num2) ? num1 : num2;
    max_num = (max_num > num3) ? max_num : num3;
    return max_num;
}

int main(){
    long long num1,num2,num3;
    if(scanf("%lld %lld %lld",&num1, &num2, &num3) != 3){
        return -1;
    }
    int min_wei = max_num(max_wei1(num1),max_wei1(num2),max_wei1(num3)) + 1;
    for(int i = min_wei; i <= 16; i++){
        if(dec2new(num1,i) * dec2new(num2,i) == dec2new(num3,i)){
            printf("%d",i);
            return 0;
        }
        
    }
    printf("0");
    return 0;


}