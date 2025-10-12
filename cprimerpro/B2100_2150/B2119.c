#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string()
{
    int capacity = 0, length = 0;
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
    int len = strlen(str1);


    if(len >= 3 && strcmp(str1 + len - 3, "ing") == 0)
        str1[len-3] = '\0';
    else if(len >= 2 && (strcmp(str1 + len - 2, "ly" ) == 0 || strcmp(str1 + len - 2, "er") == 0))
        str1[len - 2] = '\0';

    printf("%s", str1);
    free(str1);
    return 0;
}