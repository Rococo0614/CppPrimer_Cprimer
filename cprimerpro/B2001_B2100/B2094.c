#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int *arr = malloc(num*sizeof(int));
    for(int i = 0; i < num; i++)
    {
        if(scanf("%d", &arr[i]) != 1)
        return -1;
    }

    int max = arr[0],max_num = 0,max_cnt = 0;
    int sum = 0;
    for(int i = 1; i < num; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            max_num = i;
        }
    }

    for(int i = 0; i < num; i++)
    {
        if(arr[i] == max)
        {
            max_cnt++;
        }
        else
        sum += arr[i];
    }

    printf("%d", sum);
    free(arr);
    return 0;
}