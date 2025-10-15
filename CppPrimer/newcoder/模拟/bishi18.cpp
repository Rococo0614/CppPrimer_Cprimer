#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int num;
    cin >> num;
    int flag = num;
    num += 1;
    vector<string> s(num);
    for(int i = num-1; i >= 0; i--){
        int a;
        cin >> a;
        if(i == flag){
            if(a == 1 || a == -1){
                s[i] = ((a > 0) ? "" : "-") + string("x^") + to_string(i); 
            }
            else{
                s[i] = to_string(a) + "x^" + to_string(i);
            }
        }
        else{
            if(a == 0){
                s[i] = "";
            }
            else if((a == 1 || a == -1) && i != 0){
                s[i] =( (a > 0) ? "+" : "-" ) + string("x^") + to_string(i); //"+" 和 "x.^" 都是 C风格字符串字面量（类型是 const char），而 + 运算符在 C++ 中不能直接对两个 const char 做拼接**。
            }
            else if(i == 0){
                s[i] =( (a > 0) ? "+" : "") + to_string(a);
            }
            else if(i == 1){
                s[i] =((a > 0)? "+" : "") + to_string(a) + "x";
            }
            else{
                s[i] =( (a > 0) ? "+" : "" )+ to_string(a) + "x^" + to_string(i);
            }
        }
    }
    for(int i = flag; i >= 0; i--){
        cout << s[i];
    }
    return 0;
}