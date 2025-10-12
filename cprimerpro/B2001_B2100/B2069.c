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
    int q[num],p[num];
    double sum=0.0;
    q[0] = 0;
    p[0] = 0;
    q[1] = 2;
    p[1] = 1;
    for(int i = 1; i <= num; i++)
    {
        q[i+1] = q[i] + p[i];
        p[i+1] = q[i];
        sum += (double)q[i] / p[i];
    }
    return sum;
}