#include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    int total_apple = 0;
    for(int i = 1; i <= number; i++)
    total_apple += i;
    printf("%d", total_apple);
    return 0;

}