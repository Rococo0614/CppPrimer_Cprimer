#include <stdio.h>
#include <string.h>

void reverse(char *str){
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1- i] = temp;
    }
}

void dec_to_base(int num, char *str, int base){
    int n = 0;
    const char *digit = "0123456789ABCDEF";
    while(num > 0){
        str[n] = digit[num % base];
        n++;
        num /= base;
    }

    str[n] = '\0';
    reverse(str);
}

int main(){
    int m,n;
    if(scanf("%d %d", &m, &n) != 2){
        return -1;
    }
    char str[32];
    dec_to_base(m,str,n);

    printf("%s",str);
    return 0;
}