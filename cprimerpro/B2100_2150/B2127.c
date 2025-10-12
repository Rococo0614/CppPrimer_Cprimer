#include <stdio.h>

int is_fullnum(int num){
    int sum = 0;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
        sum += i;
    }
    if(sum == num)
    return 1;
    return 0;
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;
    for(int i = 2; i <= num; i++)
    {
        if(is_fullnum(i))
        printf("%d\n", i);
    }
    return 0;
}