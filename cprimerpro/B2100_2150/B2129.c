#include <stdio.h>


int max_of3(int a, int b, int c){
    a = (a >= b) ? a : b;
    int max_num = (a >= c) ? a : c;
    return max_num;
}
int main()
{
    int a,b,c;
    if(scanf("%d %d %d", &a, &b, &c) != 3)
    return -1;

    double d = (double) (max_of3(a,b,c)) / (max_of3(a+b, b,c) * max_of3(a,b,b+c));
    printf("%.3lf", d);
    return 0;
}

