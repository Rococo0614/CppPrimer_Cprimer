#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(){
    int length = 0, capacity = 0;
    int ch;
    char *str = NULL;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(length + 1 > capacity)
        {
            capacity = (capacity == 0) ? 16 : 2*capacity;
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
    if(str != NULL){
        str[length] = '\0';
    }
    else{
        str = calloc(1,sizeof(char));
        if(str == NULL) return NULL;
    }
    return str;
}

int main()
{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    while(getchar() != '\n');
    char *str = get_string();
    int len = strlen(str);
    int count = 1;
    int flag = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == str[i+1])
        count++;
        else{
            if(count >= num){
                printf("%c", str[i]);
                flag = 1;
                break;
            }
            count = 1;
        }

    }
    if(!flag)
    printf("no");
    free(str);
    return 0;
}