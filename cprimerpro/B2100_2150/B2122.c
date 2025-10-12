#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            capacity = (capacity  == 0) ? 16 : capacity * 2;
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
    int current_len = 0;
    int len = strlen(str);
    int current_state = 0;
    for(int i = 0; i <= len; i++)
    {
        if(isalpha(str[i]) && i < len)
        current_len++;
        else
        {
            if(current_len > 0)
            {
                int start = i - current_len;
                int end = i - 1;
                while(start < end)
                {
                    char temp = str[start];
                    str[start] = str[end];
                    str[end] = temp;
                    start++;
                    end--;

                }
                for(int j = i - current_len; j < i; j++)
                printf("%c", str[j]);
                printf("\n");
                current_len = 0;
            }
        }
    }
    return 0;
}