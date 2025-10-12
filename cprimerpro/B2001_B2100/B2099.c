#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr = malloc(5 * sizeof(int*));
    for(int i = 0; i < 5; i++)
    {
        arr[i] = malloc(5 * sizeof(int));
    }


    for(int i = 0; i < 5; i++)
    {
        for(int j = 0 ; j < 5; j++)
        {
            if(scanf("%d",&arr[i][j]) != 1)
            return -1;
        }
    }

    int n,m;
    if(scanf("%d %d", &n, &m) != 2)
    return -1;

    for(int i = 0; i < 5; i++)
    {
        int temp = arr[n-1][i];
        arr[n-1][i] = arr[m-1][i];
        arr[m-1][i] = temp;
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j=0; j < 5; j++)
        {
            if(j == 4)
            printf("%d\n", arr[i][j]);
            else
            printf("%d ", arr[i][j]);
        }
    }

    for(int i = 0; i < 5; i++)
    free(arr[i]);
    free(arr);

    return 0;
}