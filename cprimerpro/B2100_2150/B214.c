#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    if(scanf("%d %d", &m, &n) != 2)
    return -1;

    int **arr1 = malloc(m*sizeof(int*));
    int **arr2 = malloc(m*sizeof(int*));

    for(int i = 0; i < m; i++)
    {
        arr1[i] = malloc(n*sizeof(int));
        arr2[i] = malloc(n*sizeof(int));
    }

    for(int i = 0 ; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        if(scanf("%d", &arr1[i][j]) != 1)
        return -1;
    }

        for(int i = 0 ; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(scanf("%d", &arr2[i][j]) != 1)
                return -1;
    }
}

    for(int i = 0 ; i < m; i++)
    for(int j = 0; j < n; j++)
    {
        arr2[i][j] += arr1[i][j];
        printf("%d ", arr2[i][j]);
        if(j == n-1)
        printf("\n");
    }

    for(int i = 0; i < m; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
    }

    free(arr1);
    free(arr2);
    
    return 0;

    
}