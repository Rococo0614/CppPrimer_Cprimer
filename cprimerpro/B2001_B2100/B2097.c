#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int *arr = malloc(num *sizeof(int));
    for(int i = 0; i < num; i++)
    if(scanf("%d", &arr[i]) != 1)
    return -1;

    int flat_length = 0, flat_index = 0;
    for(int i = 0; i < num - 1; i++)
    {
        int cnt = 1;

        for(int j = i+1; j < num && arr[j] == arr[i]; j++)
        {
            cnt++;
        }

        flat_length = (cnt > flat_length ? cnt : flat_length);
    }

    printf("%d", flat_length);
    free(arr);
    return 0;
}