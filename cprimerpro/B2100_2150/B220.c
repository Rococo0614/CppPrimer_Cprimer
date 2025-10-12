#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int main()
{
    int length = 0;
    int capacity = 0;
    char *str = NULL;
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(length +1 >= capacity)
        {
            capacity = (capacity == 0) ? 16 : capacity * 2;
            char *temp = realloc(str, capacity*sizeof(char));
            if(temp == NULL)
            {
                free(str);
                return -1;
            }
            
            str = temp;
        }

        str[length++] = (char)ch;
    }

    int found = 1;
    for(int i = 0; i < length; i++)
    {
        int flag = 0;
        for(int j = 0; j < length; j++)
        {
            if(i != j && str[i] == str[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            putchar(str[i]);
            found = 0;
            break;
        }

    }

    if(found)
    fputs("no",stdout);



    if(str != NULL)
    str[length] = '\0';
    else
    str = calloc(1,sizeof(char));

    free(str);
    return 0;

}