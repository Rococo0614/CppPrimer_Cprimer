#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    int number;
    float grades;
};

void swap(float *x,float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(float score[], int num){
    for(int i = 0; i < num - 1; i++){
        if(score[i] > score[i+1]){
            swap(&score[i], &score[i+1]);
        }

    }
}

void bubblesort(float a[],int num){

    for(int i = num; i > 1; i--){
        bubble(a,i);
    }
}


int main(){
    int num,k;
    if(scanf("%d %d", &num, &k) != 2){
        return -1;
    }

    struct student b2158[num];
    float *a = malloc(num*sizeof(float));
    for(int i = 0; i < num; i++){
        scanf("%d %g", &b2158[i].number, &b2158[i].grades);
        a[i] = b2158[i].grades;

    }

    bubblesort(a,num);
    for(int i = 0; i < num; i++){
        if(b2158[i].grades == a[num-k]){
            printf("%d %g", b2158[i].number,b2158[i].grades);
            break;
        }
    }
    free(a);
    return 0;
}