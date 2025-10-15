#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char str[20];
    cin >> str;
    int len = strlen(str);
    if(str[0] >= '0' && str[0] <= '9'){
        cout << "no";
        return 0;
    }


    for(int i = 1; i < len; i++){
        if((str[i] >= '0' && str[i] <= '9') || (str[i]>= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')||(str[i] == '_'));
        else{
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}