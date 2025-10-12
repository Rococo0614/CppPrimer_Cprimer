#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

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
    int max_state = 0, min_state = 0;
    int max_num = 0, min_num = INT_MAX;
    int current_len = 0;
    for(int i = 0; i <= len; i++)
    {
        if(isalpha(str[i]) && i < len)
        current_len++;
        else
        {
            if(current_len > 0)
            {
                if(current_len > max_num)
            {
                max_num = current_len;
                max_state = i-current_len;
            }
            if(current_len < min_num)
            {
                min_num = current_len;
                min_state = i - current_len;
            }
            current_len = 0;

            }

        }
    }

    for(int i = 0; i < max_num ; i++)
    printf("%c", str[max_state+i]);
    printf("\n");
    for(int i = 0; i < min_num; i++)
    printf("%c", str[min_state+i]);
    printf("\n");

    free(str);
    return 0;
}