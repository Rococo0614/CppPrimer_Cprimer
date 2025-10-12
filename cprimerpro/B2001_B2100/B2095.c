#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    double *arr = malloc(num*sizeof(double));
    for(int i = 0; i < num; i++){
        if(scanf("%lf", &arr[i]) != 1){
        return -1;}
    }

    double min = arr[0], max = arr[0], average = 0;
    int cnt = 0,max_idx = 0, min_idx = 0;
    for(int i = 1; i < num; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            min_idx = i;
        }
        if(arr[i] > max)
        {
            max = arr[i];
            max_idx = i;
        }
    }


    for(int i = 0; i < num; i++)
    {
        if( i != max_idx && i != min_idx)
        average += arr[i];
    }

    average /= (num - 2);
    double abs_err = 0;

    for(int i = 0; i < num; i++)
    {
        if(i != max_idx && i != min_idx)
        {
            if(fabs(arr[i] - average) > abs_err)
            abs_err = fabs(arr[i] - average);
        }
    }

    printf("%.2lf %.2lf", average, abs_err);
    free(arr);
    return 0;
}