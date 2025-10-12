#include <stdio.h>

int main()
{
    char n;
    int num;
    scanf("%c", &n);
    num = n;
    num = num % 2;
    if(num == 0)
    printf("NO");
    else
    printf("YES");
    return 0;
}