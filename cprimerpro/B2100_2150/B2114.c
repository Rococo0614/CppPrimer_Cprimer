#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string()
{
    int length = 0, capacity = 0;
    int ch;
    char *str = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(length + 1 > capacity)
        {
            capacity = (capacity == 0) ? 16 : capacity * 2;
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
    char *str2 = malloc(strlen(str1) + 1);

    int flag = 0;

    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] != 'A' && str1[i] != 'T' && str1[i] != 'G' && str1[i] != 'C')
        {
            free(str1);
            return -1;
        }
    }

    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == 'A')
        str2[i] = 'T';
        else if(str1[i] == 'T')
        str2[i] = 'A';
        else if(str1[i] == 'C')
        str2[i] = 'G';
        else
        str2[i] = 'C';
    }
    str2[strlen(str1)] = '\0';

    fputs(str2, stdout);
    free(str2);
    free(str1);
    return 0;
}