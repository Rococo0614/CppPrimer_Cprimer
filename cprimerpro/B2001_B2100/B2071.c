#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b);
int find_min_prime_number(int num);

int main()
{
    int a,b,c,x;
    scanf("%d %d %d", &a, &b, &c);
    x = gcd(gcd(abs(a-b),abs(a-c)), abs(b-c));
    printf("%d",find_min_prime_number(x));


    return 0;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int find_min_prime_number(int num)
{
    int cnt = 0;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        return i;
        else
        return num;
    }
}

// 尝试利用题目隐含的数学性质：寻找a，b，c两两作差的最大公约数