#include <stdio.h>

int main()
{
    int grades[3];
    for( int i = 0; i < 3; i++ )
    scanf("%d", &grades[i]);
    int fail_num = 0;
    for(int i = 0; i < 3; i++)
    {
        if(grades[i] < 60)
        {
            fail_num++;    
        }
    };
    if(fail_num == 1)
    printf("1");
    else
    printf("0");
    return 0;

}