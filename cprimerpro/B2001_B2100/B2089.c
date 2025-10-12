#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    return -1;

    int *num = malloc (n * sizeof(int));
    for(int i = 0; i < n; i++)
    scanf("%d", &num[i]);

    for(int i = 0; i < n / 2; i++)
    {
        int temp = num[i];
        num[i] = num[n-i-1];
        num[n-i-1] = temp;
    }

    for(int i = 0; i < n; i++)
    printf("%d ", num[i]);
    free(num);
    return 0;
}