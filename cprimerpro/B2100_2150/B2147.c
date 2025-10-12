#include <stdio.h>
#include <math.h>

double f_hanshu(double x, int n){
    if(n == 1){
        return sqrt(1+x);
    }
    else{
        return sqrt(n+f_hanshu(x,n-1));
    }
}

int main(){
    double x;
    int n;
    if(scanf("%lf %d", &x, &n) != 2){
        return -1;
    }

    printf("%.2lf", f_hanshu(x,n));
    return 0;
}