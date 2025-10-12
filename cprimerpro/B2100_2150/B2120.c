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
    char *str = get_string();
    int len = strlen(str);
    int is_word = 0;
    int word_length = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ')
        {
            word_length++;
            is_word = 1;
        }
        else
        {
            if(is_word)
            {
                printf("%d,", word_length);
                is_word = 0;
                word_length = 0;
            }
        }



    }

            if(is_word)
        {
            printf("%d", word_length);
        }
    free(str);
    return 0;
}