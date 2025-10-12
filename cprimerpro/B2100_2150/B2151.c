#include <stdio.h>

int main(){
    int num;
    if(scanf("%d", &num) != 1){
        return -1;
    }

    int cnt = 0,max_state = 0;
    for(int i = 0; i < num; i++){
        int num1,num2;
        if(scanf("%d %d", &num1, &num2) != 2){
            return -1;
        }

        if((num1 >= 90 && num1 <= 140) && (num2 >= 60 && num2 <= 90)){
            cnt++;
        }
        else{
            if(cnt > max_state){
                max_state = cnt;
            }
            cnt = 0;
        }
    }
    if(cnt > max_state){
        max_state = cnt;
    }
    printf("%d",max_state);
    return 0;
}