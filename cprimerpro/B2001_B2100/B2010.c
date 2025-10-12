#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d", &a, &b);
    c = a / b;
    a = a - b * c;
    printf("%d %d", c, a);
    return 0;
 

}