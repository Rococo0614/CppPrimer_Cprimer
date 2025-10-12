#include <stdio.h>

int main()
{
    int a,b,temp;
    char c;
    _Bool d;
    if(scanf("%d %d %c %d", &a, &b, &c, &temp) != 4)
    return -1;

    d = temp;
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(i == 1 || i == a)
            printf("%c",c);
            else if(d != 1)
            {
                if(j == 1 || j == b)
                printf("%c", c);
                else
                printf(" ");
            }
            else
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}