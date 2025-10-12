#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int capacity = 0;
    int digit_count = 0;
    int length = 0;
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
        if(isdigit(ch))
        digit_count++;
    }

    if(str != NULL)
    str[length] = '\0';
    else
    str = calloc(1,sizeof(char));


    free(str);
    printf("%d", digit_count);
    return 0;
}