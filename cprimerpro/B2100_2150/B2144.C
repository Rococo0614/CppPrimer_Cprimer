#include <stdio.h>
#include <stdlib.h>

int Ackerman(int num1, int num2){
    if((num1> 3 ||num1 < 0) || (num2 > 10 && num2 < 0)){
        return -1;
    }
    if(num1 == 0){
        return num2+1; 
    }
    else if(num2 == 0 && num1 > 0){
        return Ackerman(num1 -1, 1);
    }
    else if(num1 > 0 && num2 > 0){
        return Ackerman(num1 -1, Ackerman(num1, num2 -1));
    }
}

int main(){
    int m,n;
    if(scanf("%d %d", &m, &n) != 2){
        return -1;
    }

    printf("%d", Ackerman(m,n));
    return 0;
}