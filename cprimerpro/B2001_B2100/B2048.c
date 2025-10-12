#include <stdio.h>
#include <math.h>

int main()
{
    int weight, fee = 0;
    char needfast;
    scanf("%d %c", &weight, &needfast);
    if (needfast == 'y')
    fee += 5;
    if (weight <= 1000)
    fee += 8;
    else
    {
        double n = (weight - 1000.0) / 500.0;
        if (fmod(n, 1.0) == 0)
        {
            int num = n;
            fee += 8 + num * 4;
        }
        else
        {
        int num = n + 1;
        fee += 8 + num * 4;
        }
    }
    printf("%d", fee);
    return 0;

}