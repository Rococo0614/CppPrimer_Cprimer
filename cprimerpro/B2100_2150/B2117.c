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

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;
    getchar();

    char *str[num];
    for(int i = 0; i < num; i++)
    {
        str[i] = get_string(); 
        for(int j = 0; j < strlen(str[i]); j++)
        {
            if(j == 0)
            {
                if(str[i][j] >= 'a' && str[i][j] <= 'z')
                str[i][j] -= 'a' - 'A';
            }
            else if(j != 0)
            {
                if(str[i][j] >= 'A' && str[i][j] <= 'Z')
                str[i][j] += 'a' - 'A';
            }
            else
            ;
        }

    }

    for(int i = 0; i < num; i++)
    {
        fputs(str[i],stdout);
        printf("\n");
    }
    
    for(int i = 0; i < num; i++)
    free(str[i]);

    return 0;



}