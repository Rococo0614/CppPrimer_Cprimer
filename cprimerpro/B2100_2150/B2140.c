#include <stdio.h>
#include <stdbool.h>

bool isA(int num){
    int cnt1 = 0, cnt0 = 0;
    while(num > 0){

        if(num % 2 == 0){
            cnt0++;
        }
        else{
            cnt1++;
        }
        num /= 2;
    }
    return cnt1 > cnt0;
}

int main(){
    int num;
    if(scanf("%d", &num) != 1){
        return -1;
    }

    int cntA = 0, cntB = 0;
    for(int i = 1; i <= num; i++){
        if(isA(i)){
            cntA++;
        }
        else{
            cntB++;
        }
    }
    printf("%d %d", cntA, cntB);
    return 0;
}