#include <stdio.h>

double f_hanshu(double x, int n){
    if(n < 1){
        return -1;
    }
    else if(n == 1){
        return x / (1 + x);
    }
    else{
        return x / (n + f_hanshu(x,n-1));
    }
}

int main(){
    double x;
    int n;
    if(scanf("%lf %d", &x, &n) != 2){
        return -1;
    }

    printf("%.2lf",f_hanshu(x,n));
    return 0;
}
