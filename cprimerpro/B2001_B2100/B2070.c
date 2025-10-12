#include <stdio.h>

double divide_sum(int num);

int main()
{
    int num;
    scanf("%d", &num);
    printf("%.4lf", divide_sum(num));
    return 0;

}

double divide_sum(int num)
{
    double sum = 0.0;
    for(int i = 1; i <= num; i++)
    {
        if(i % 2 == 0)
        sum +=  (-1) * (1 / (double)i);
        else
        sum +=  (1 / (double)i);
    }
    return sum;
}