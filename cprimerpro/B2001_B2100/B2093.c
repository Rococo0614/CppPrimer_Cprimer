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

    int choose = 0;
    if(scanf("%d", &choose) != 1)
    return -1;

    int flag = 0;
    for(int i = 0; i < num; i++)
    {
        if(a[i] == choose)
        {
            printf("%d", i);
            flag = 1;
            return 0;
    
        }
    }

    if(flag == 0)
    printf("-1");
    free(a);
    return 0;
}