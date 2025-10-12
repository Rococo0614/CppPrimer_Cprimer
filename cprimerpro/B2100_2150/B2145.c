#include <stdio.h>

int digit(long long n, int k){
    int num2re = 0;
    for(int i = 0; i < k; i++){
        num2re = n % 10;
        n /= 10;
    }
    return num2re;
}

int main(){
    long long n;
    int k;
    if(scanf("%lld %d", &n, &k) != 2){
        return -1;
    }
    printf("%d", digit(n,k));
    return 0;
}