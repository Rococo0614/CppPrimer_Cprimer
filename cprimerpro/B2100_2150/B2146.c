#include <stdio.h>
#include <stdlib.h>

int Hermite(int n, int x){
    if(n == 0){
        return 1;
    }
    else if(n ==1){
        return 2*x;
    }
    else{
        return 2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x);
    }
}

int main(){
    int n,x;
    if(scanf("%d %d", &n, &x) != 2){
        return -1;
    }
    printf("%d",Hermite(n,x));
    return 0;
}