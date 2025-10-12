#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    char stage[10];
    scanf("%d", &num);
    if(num % 3  == 0)
    {
        if(num % 5 == 0)
        {
            if(num % 7 == 0)
            strcpy(stage, "3 5 7");
            else
            strcpy(stage, "3 5");
        }
        else if(num % 7 == 0)
        strcpy(stage, "3 7");
        else 
        strcpy(stage, "3");
    }
    else if(num % 5 == 0)
    {
        if(num % 7 == 0)
        strcpy(stage, "5 7");
        else
        strcpy(stage, "5");
    }
    else if(num % 7 == 0)
    strcpy(stage, "7");
    else 
    strcpy(stage, "n");
    printf("%s",stage);
    return 0;
}