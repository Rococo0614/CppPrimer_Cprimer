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
    else{
        str = calloc(1, sizeof(char));
        if(str == NULL) return NULL;
    }

    return str;
}

int main()
{
    char *str = get_string();
    int len = strlen(str);
    int end = len-1;
    int start = 0;
    char *str2 = malloc(len*sizeof(char)+1);
    while(start <= end)
    {
        str2[start] = str[end];
        str2[end] = str[start];
        start++;
        end--;
    }
    str2[len] = '\0';
    if(!strcmp(str, str2))
    {
        printf("yes");
    }
    else
    printf("no");
    free(str2);
    free(str);
    return 0;

}