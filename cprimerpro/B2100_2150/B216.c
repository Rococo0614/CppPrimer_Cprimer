#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    if(scanf("%d %d", &m, &n) != 2)
    return -1;

    int **arrA = malloc(m*sizeof(int*));
    int **arrAT = malloc(n*sizeof(int*));
    for(int i = 0; i < m; i++)
    arrA[i] = malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++)
    arrAT[i] = malloc(m*sizeof(int));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(scanf("%d", &arrA[i][j]) != 1)
            {
                for(int i = 0 ; i < m; i++)
                free(arrA[i]);
                free(arrA);
                for(int j = 0; j < n; j++)
                free(arrAT[j]);
                free(arrAT);
            }
            arrAT[j][i] = arrA[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("%d ", arrAT[i][j]);
                if(j == m - 1)
                printf("\n");
            }
        }

    for(int i = 0 ; i < m; i++)
    free(arrA[i]);
    free(arrA);
    for(int j = 0; j < n; j++)
    free(arrAT[j]);
    free(arrAT);


}