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

    for(int i = 0; i < num; i++)
    {
        for(int j = i + 1; j < num; j++)
        {
            if(arr[j] == arr[i] && arr[j] != 0)
            arr[j] = 0;
        }

        if(arr[i] != 0)
        printf("%d ", arr[i]);

    }

    free(arr);
    return 0;
}