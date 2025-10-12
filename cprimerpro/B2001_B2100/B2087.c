#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    return -1;

    int *num = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    scanf("%d", &num[i]);

    int m;
    if(scanf("%d", &m) != 1)
    return -1;

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(num[i] == m)
        cnt++;
    }

    free(num);
    printf("%d", cnt);
    return 0;

}