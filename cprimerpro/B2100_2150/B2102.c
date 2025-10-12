#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr = malloc(5*sizeof(int*));
    for(int i=0; i < 5; i++)
    arr[i] = malloc(5*sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(scanf("%d", &arr[i][j]) != 1)
            return -1;
        }
    }

for (int i = 0; i < 5; i++)
{
    int andian = arr[i][0];
    int col = 0;       // 当前最大值所在列
    int row = i;

    for (int j = 1; j < 5; j++)
    {
        if (arr[i][j] > andian)
        {
            andian = arr[i][j];
            col = j;
        }
    }

    int ok = 1; 
    for (int k = 0; k < 5; k++)
    {
        if (arr[k][col] < andian)
        {
            ok = 0;
            break;
        }
    }

    if (ok)
    {
        printf("%d %d %d\n", row+1, col+1, andian);
        for (int t = 0; t < 5; t++) free(arr[t]);
        free(arr);
        return 0;
    }
}

printf("not found\n");
    for(int i = 0; i < 5; i++)
    free(arr[i]);
    free(arr);

    return 0;
}