#include <stdio.h>

int main(){
    int years;
    if(scanf("%d", &years) != 1){
        return -1;
    }

    if(years % 400 == 0){
        printf("Y");
    }
    else if(years % 4 == 0 && years % 100 != 0){
        printf("Y");
    }
    else{
        printf("N");
    }

    return 0;
}