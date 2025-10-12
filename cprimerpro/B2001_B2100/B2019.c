#include <stdio.h>

int main()
{
    int num;
    _Bool chs;
    scanf("%d",&num);
    chs = num ;
    num = chs ;
    printf("%d", num);
}