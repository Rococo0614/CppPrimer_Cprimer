#include <stdio.h>

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    int temp = num;
    for(int i = 2; i*i <= temp; i++)
    {
        while(temp % i == 0)
            temp /= i;
    }
    printf("%d", temp);
    return 0;
}