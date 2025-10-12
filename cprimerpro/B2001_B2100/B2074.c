#include <stdio.h>

int main()
{
    const char *day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"} ;
    int a,b,days;
    scanf("%d %d", &a, &b);
    days = a;
    for(int i = 1; i < b; i++)
    days = a * days % 7;
    printf("%s", day[days - 1]);
    return 0;
}