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
    str[length] = '\0';
    else
    {
        str = calloc(1, sizeof(char));
        if(str == NULL)
        return NULL;
    }

    return str;

}


int main()
{
    char *str1 = get_string();
    char *str2 = malloc(strlen(str1) + 1);
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str2[i] = str1[i] + ('a' - 'A');
        }
        else if(str1[i] >= 'a' && str1[i] <= 'z')
        {
            str2[i] = str1[i] - ('a' - 'A');
        }
        else
        {
            free(str2);
            free(str1);
            return -1;
        }
    }

    for(int i = 0; i < (strlen(str1)) / 2; i++)
    {
        char temp = str2[i];
        str2[i] = str2[strlen(str1) - i - 1];
        str2[strlen(str1)-1-i] = temp;
        
    }

    for(int i = 0; i < strlen(str1); i++)
    {
        if(str2[i] == 'x' || str2[i] == 'y' || str2[i] == 'z' || str2[i] == 'X' || str2[i] == 'Y' || str2[i] == 'Z')
        {
        switch(str2[i])
        {
            case 'x' : str2[i] = 'a'; break;
            case 'y' : str2[i] = 'b'; break;
            case 'z' : str2[i] = 'c'; break;
            case 'X' : str2[i] = 'A'; break;
            case 'Y' : str2[i] = 'B'; break;
            case 'Z' : str2[i] = 'C'; break;
        }
    }

    else
    str2[i] = str2[i] + 3;
    }


    str2[strlen(str1)] = '\0';
    fputs(str2, stdout);
    free(str2);
    free(str1);
    return 0;
}

