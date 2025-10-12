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

struct player
{
    char *name;
    int marks;
};

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;
    int max_num = 0;

    struct player ones[num];
    while(getchar() !='\n');
    for(int i = 0; i < num; i++)
    {

        scanf("%d", &ones[i].marks);
        while(getchar() != ' '); 
        ones[i].name = get_string();
        if(ones[i].marks > max_num)
        max_num = ones[i].marks;
    }

    for(int i = 0; i < num; i++)
    {
        if(ones[i].marks == max_num)
        {
            printf("%s", ones[i].name);
            break;
        }
    }

    for(int i = 0; i < num; i++)
    {
        free(ones[i].name);
    }

    return 0;
}