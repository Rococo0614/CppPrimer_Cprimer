#include <stdio.h>
#include <math.h>

int main(){
    double x;
    int n;
    if(scanf("%lf %d",&x,&n) != 2){
         return -1;
    }

    double f = x + 1;

    for(int i = 1; i <= n; i++){
        f = sqrt(f+i);
    }
    printf("%.2lf", f);
}