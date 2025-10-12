#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string()
{
    int capacity = 0,length = 0;
    int ch;
    char *str = NULL;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(length + 1 > capacity)
        {
            capacity = (capacity == 0) ? 16 : 2 * capacity;
            char *temp =realloc(str, capacity);
            if(temp == NULL)
            {
                free(str);
                return NULL;
            }
            str = temp;

        }

        str[length++] = (char)ch;
    }

    if(str != NULL)
    {
        str[length] = '\0';
    }
    else
    {
        str = calloc(1, sizeof(char));
        if(str == NULL) return NULL;
    }

    return str;
}

int main()
{
    char *str1 = get_string();
    char *str2 = malloc(strlen(str1) +1);
    if(str2 == NULL)
    {
        free(str2);
        return -1;
    }
    for(int i = 0; i < strlen(str1) - 1; i++)
    {
        str2[i] = (char) (str1[i] + str1[i+1]);
    }
    str2[strlen(str1)-1] = (char)(str1[strlen(str1)-1] + str1[0]);
    fputs(str2, stdout);
    return 0;

    free(str1);
    free(str2);

}