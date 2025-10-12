#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int *arr = malloc(num *sizeof(int));
    for(int i = 0; i < num; i++)
    if(scanf("%d", &arr[i]) != 1)
    return -1;

    int max = 0;
    for(int i = 0; i < num; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }

    for(int j = 0; j <= max; j++)
    {
        int cnt = 0;
        for(int i = 0; i < num; i++)
        {
            if(arr[i] == j)
            cnt++;
        }
        printf("%d\n", cnt);
    }

    free(arr);
    return 0;
}