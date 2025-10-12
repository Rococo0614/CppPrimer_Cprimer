#include <stdio.h>
#include <string.h>

// int main()
// {
//     char num[3];
//     for(int i = 0; i < 3; i++)
//     num[i] = getchar();
//     for(int i = 2; i > -1; i--)
//     putchar(num[i]);
//     return 0;

// }

int main()
{
    int num;
    scanf("%d", &num);
    int b, s, g;
    b = num / 100;
    s = (num - 100 * b) / 10;
    g = num - 100 * b - 10 * s;
    printf("%d%d%d", g, s, b);
    return 0;
}
//两种办法，看你想用那种;)