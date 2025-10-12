#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string()
{
    int capacity = 0, length = 0;
    int ch;
    char *str;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(length + 1 > capacity)
        {
            capacity = (capacity == 0) ? 16 : 2 *capacity;
            char *temp = realloc(str, capacity); 
            if(temp == NULL)
            {
                free(str);
                return NULL;
            }
            str = temp;           
        }
        str[length++] = (char) ch;
    } 
    if(str != NULL)
    str[length] = '\0';
    else
    {
        str = calloc(1, sizeof(char));
        if(str == NULL) return NULL;
    }

    return str;
}

int main()
{
    char *str = get_string();
    int len = strlen(str);
    int count = 1;
    for(int i = 0; i < len; i++)
    {

        if(str[i] == str[i + 1])
        count++;
        else
        {
            printf("%d%c",count, str[i]);
            count = 1;
        }
    }

    free(str);
    return 0;
}