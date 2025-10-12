#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sum(int n){
    return n * (1+ n) / 2;
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    for(int i = 1; ; i++)
    {
        int total = sum(i);
        int numerator = total - num;
        if(numerator <= 0) continue;
        if(numerator % 3 == 0){
            int x = numerator / 3;
            if(x <= i && x >=1)
            printf("%d %d", x, i);
            break;
        }
        

    }

    return 0;
}