#include <stdio.h>
#include <stdlib.h>

int judgement(int number);

int main()
{
    int num_count = 0, cnt = 0;
    scanf("%d", &num_count);
    int *number = malloc(num_count*sizeof(int));
    for(int i = 0; i < num_count; i++)
    {
        scanf("%d", &number[i]);
        if(judgement(number[i]) == 1)
        cnt++;
    }
    printf("%d", cnt);
    return 0;

}

int judgement(int number)
{
    int a,b,c,d = 0;
    a = number / 1000;
    b = (number - 1000 * a) / 100;
    c = (number - 1000* a - 100 * b) / 10;
    d = number % 10;
    if(d - a - b - c > 0)
    return 1;
    else 
    return 0;
}