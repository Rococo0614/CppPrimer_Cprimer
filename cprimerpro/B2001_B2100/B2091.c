#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int *a = malloc(num*sizeof(int));
    for(int i = 0; i < num; i++)
    {
        if(scanf("%d", &a[i]) != 1)
        return -1;
    }

    int *b = malloc(num*sizeof(int));
    for(int i = 0; i < num; i++)
    {
        if(scanf("%d", &b[i]) != 1)
        return -1;
    }

    int sum = 0;
    for(int i = 0; i < num; i++)
    {
        sum += a[i] * b[i];
    }

    free(b);
    free(a);

    printf("%d", sum);
    return 0;

}