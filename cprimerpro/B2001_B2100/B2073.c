#include <stdio.h>

// int main()
// {
//     int a,b,n;
//     scanf("%d %d %d", &a, &b, &n);
//     double c = (double) a / b;
//     for(int i = 0; i < n; i++)
//     c = c * 10;
//     a = (int) c % 10;
//     printf("%d", a);
//     return 0;
// } 这样取值会由于double的精度限制，在无限循环和不循环小数中从存在精度导致的错误问题
// 可以使用手除法，要找第n位小数，对分数进行n次乘10取余的循环

int main()
{
    int a,b,n;
    scanf("%d %d %d",&a, &b, &n);
    int r = a % b,q;
    for(int i = 0; i < n; i++)
        {
            r = r * 10;
            q = r / b;
            r = r % b;
        }
    printf("%d", q);
    return 0;
}