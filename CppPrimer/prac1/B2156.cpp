#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char str[501];
    cin.getline(str,501,'.');
    int len = strlen(str);
    int longnum = 0,cnt = 0,longnum_index;
    for(int i = 0;i < len ; i++){
            if(str[i] != ' '){
                cnt++;
            }
            else{
                if(cnt > longnum){
                    longnum = cnt;
                    cnt = 0;
                    longnum_index  = i - longnum;
                }
                else{
                    cnt = 0;
                }
            }
    }
    if(cnt > longnum){
        longnum = cnt;
        longnum_index = strlen(str) - longnum;
    }
    for(int i = longnum_index ; i < longnum_index + longnum;i++){
        cout << str[i];
    }
    return 0;
}