#include <stdio.h>

int main()
{
    int date;
    scanf("%d", &date);
    if(date == 1 || date == 3 || date == 5)
    printf("NO");
    else 
    printf("YES");
    return 0;
}