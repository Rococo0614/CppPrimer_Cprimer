#include <stdio.h>

int main()
{
    int lucky, good;
    scanf("%d %d", &lucky, &good);
    if(lucky >= 10)
    printf("1");
    else if(good >= 20)
    printf("1");
    else
    printf("0");
    return 0;
}