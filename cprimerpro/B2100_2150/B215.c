#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,k;
    if(scanf("%d %d %d", &m, &n, &k) != 3)
    return -1;

    int **arr1 = malloc(m*sizeof(int*));
    int **arr2 = malloc(n*sizeof(int*));

    for(int i = 0; i < m; i++)
    arr1[i] = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    arr2[i] = malloc(k*sizeof(int));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        if(scanf("%d", &arr1[i][j]) != 1)
        {
            for(int k = 0; k < m; k++)
            free(arr1[k]);
            free(arr1);
            return -1;

        }
    }

    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            if(scanf("%d", &arr2[i][j]) != 1)
        {
            for(int k = 0; k < n; k++)
            free(arr2[k]);
            free(arr2);
            return -1;

        }
        }

    int **arr3 = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++)
    arr3[i] = malloc(k*sizeof(int));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            arr3[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", arr3[i][j]);
            if(j == k - 1)
            printf("\n");
        }
    }

    for(int i = 0; i < m; i++)
    free(arr3[i]);
    free(arr3);
    for(int i = 0; i < n; i++)
    free(arr2[i]);
    free(arr2);
    for(int i = 0; i < m; i++)
    free(arr1[i]);
    free(arr1);
    
    return 0;

}