#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* read_dynamic_string(){
    int capacity = 0;
    int length = 0;
    char *str = NULL;
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF )
    {
        if(length +1 > capacity)
        {
            capacity = (capacity == 0) ? 16 :capacity * 2;
            char *temp = realloc(str,capacity*sizeof(char));
            if(temp == NULL)
            {
                free(str);
                return NULL;
            }
            str = temp;
        }
        str[length++] = (char)ch;

    }

    if(str != NULL)
    {
        if(length +1 > capacity)
        {
            char *temp = realloc(str, length + 1);
            if(temp == NULL)
            {
                free(str);
                return NULL;
            }
            str = temp;
        }
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
    double same_rate;
    if(scanf("%lf", &same_rate) != 1)
    return -1;
    getchar(); //消耗缓冲区的换行符
    char *str1 = read_dynamic_string();
    int len = strlen(str1);
    char *str2 = read_dynamic_string();
    if(strlen(str2) != len)
    {
        free(str1);
        free(str2);
        return -1;
    }
    int same_digit = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == str2[i])
        same_digit++;
    } 

    double same_rate1 = (double) same_digit / strlen(str1);
    if(same_rate1 >= same_rate)
    fputs("yes", stdout);
    else
    fputs("no",stdout);

}