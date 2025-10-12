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
        if(length +1 > capacity)
        {
            capacity = (capacity == 0) ? 16 : 2 * capacity;
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

int is_substring(char *str1, char *str2)
{
    if(*str2 == '\0')
    return 1;
    else
    {
        for(int i = 0; str1[i] != '\0'; i++)
        {
            int j = 0;
            while(str2[j] != '\0' && str1[i+j] == str2[j])
            j++;
            if(str2[j] == 0)
            return 1;
        }  
    }
    return 0;
}

int main()
{
    char *str1 = get_string();
    char *str2 = get_string();
    if(is_substring(str1, str2) || *str2 == '\0')
    {
        printf("%s is substring of %s", str2, str1);
    }
    else if(is_substring(str2,str1) || *str1 == '\0')
    {
        printf("%s is substring of %s", str1, str2);
    }
    else
    printf("No substring");



    free(str2);
    free(str1);
    return 0;
}