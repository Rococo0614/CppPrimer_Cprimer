#include <stdio.h>

int main()
{
    long double number;
    long long number1;
    scanf("%Lf", &number);
//   if ( number >= 0 || number <= -1 )
    number1 = number;
//    else
//    number1 = -1;
    printf("%lld", number1);
    return 0;
}