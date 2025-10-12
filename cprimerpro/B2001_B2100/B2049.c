#include <stdio.h>

int main()
{
    long int num[3], max_num;
    for(int i = 0; i < 3; i++)
    scanf("%ld", &num[i]);
    max_num = num[0];
    for(int i = 0 ; i < 3; i++)
    if(num[i] > max_num)
    max_num = num[i];
    printf("%ld", max_num);
    return 0;


} //比较数组数字的时候，在输入确定结果后将任意的数初始化给变量，然后进行比较就非常方便了；