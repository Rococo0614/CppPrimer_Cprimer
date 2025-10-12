#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    if(scanf("%d %d", &m, &n) != 2)
    return -1;

    int **arrA = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++)
    arrA[i] = malloc(n*sizeof(int));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(scanf("%d", &arrA[i][j]) != 1)
            {
                for(int i = 0; i < m; i++)
                free(arrA[i]);
                free(arrA);
            }
        }
    }


    int **arrAR = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++)
    arrAR[i] = malloc(n*sizeof(int));

    for(int i = 0 ; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                arrAR[i][j] = arrA[i][j];
            }
            else {
                double sum = arrA[i][j-1] + arrA[i-1][j] + arrA[i+1][j] + arrA[i][j+1] + arrA[i][j];
                sum = sum / 5.0;
                arrAR[i][j] = (int) (sum + 0.5);

        }
    }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arrAR[i][j]);
            if(j == n-1)
            printf("\n");
        }
    }

    for(int i = 0; i < m; i++)
    free(arrAR[i]);
    free(arrAR);

    for(int i =0 ; i < m ; i++)
    free(arrA[i]);
    free(arrA);

    return 0;
}