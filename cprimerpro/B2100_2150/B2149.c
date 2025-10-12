#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    if(scanf("%d %d %d", &a, &b, &c) != 3){
        return -1;
    }

    if((a+b)>=c &&(b+c)>= a &&(c+a)>= b){
        double s = (0.5) * (a + b + c);
        double mianji= sqrt(s*(s-a)*(s-b)*(s-c));
        printf("%.2lf", mianji);
    }
    else printf("No solution");

    return 0;
}