#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j;
    if(scanf("%d %d %d", &N, &i, &j) != 3)
    return -1;

    for(int n = 1; n <= N; n++)
    printf("(%d,%d) ",i,n);
    printf("\n");

    for(int n = 1; n <= N; n++)
    printf("(%d,%d) ",n,j);
    printf("\n");

    int flag_x = i, flag_y = j;
    while(flag_x > 1 && flag_y > 1)
    {
        flag_x -= 1;
        flag_y -= 1;
    }

    while(flag_x <= N && flag_y <=N)
    {
        printf("(%d,%d) ", flag_x, flag_y);
        flag_x ++;
        flag_y ++;
    }
    printf("\n");

    flag_x = i;
    flag_y = j;
    while(flag_x < N && flag_y > 1)
    {
        flag_x++;
        flag_y -= 1;
    }

    while(flag_x >= 1 && flag_y <=N)
    {
        printf("(%d,%d) ", flag_x, flag_y);
        flag_x -= 1;
        flag_y ++;
    }

    return 0;

}