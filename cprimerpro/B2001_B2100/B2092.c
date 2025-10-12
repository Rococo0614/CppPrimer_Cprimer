#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int *a = malloc(num*sizeof(int));
    for(int i = 0; i < num; i++)
    a[i] = 1;

    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= num; j++)
        {
            if(j % i == 0)
            a[j - 1] *= -1;
        }
    }

    for(int i = 0; i < num; i++)
    {
        if(a[i] == -1)
        printf("%d ", i+1);
    }

    free(a);
    return 0;
}