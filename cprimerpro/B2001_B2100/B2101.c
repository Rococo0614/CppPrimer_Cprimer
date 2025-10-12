#include <stdio.h>
#include <stdlib.h>

int main()
{
    int col,side;
    if(scanf("%d %d", &col, &side) != 2)
    return -1;

    int **arr = malloc(col*sizeof(int*));
    for(int i = 0; i < col; i++)
    {
        arr[i] = malloc(side*sizeof(int));
    }

    int sum = 0;

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < side; j++)
        {
            if(scanf("%d", &arr[i][j]) != 1)
            return -1;
            if(i*j == 0 || i == col -1 || j == side - 1)
            sum += arr[i][j];
        }
    }

    printf("%d", sum);
    for(int i = 0; i < side; i++)
    free(arr[i]);
    free(arr);

    return 0;



}