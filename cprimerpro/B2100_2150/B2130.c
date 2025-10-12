#include <stdio.h>

int main()
{
    int a,b;
    int result;
    char k;
    if(scanf("%d%c%d", &a, &k, &b) != 3)
    return -1;
    switch(k){
        case '+' :result = a + b;break;
        case '-' :result = a - b;break;
        case '*' : result = a * b;break;
        case '/' : result = a / b;break;
        case '%' : result = a % b;break;
    }
    printf("%d", result);
    return 0;
}