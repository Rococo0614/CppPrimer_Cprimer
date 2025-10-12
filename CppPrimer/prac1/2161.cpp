#include <iostream>
#include <string>
using namespace std;


string dec_to_bin(int num){
    if(num == 0){
        return "0";
    }
    string a = "01";
    int n = 0;
    string u;
    while(num > 0){
        u += a[num % 2];
        num /= 2;
        n++;
    }
    return u;
}

int main(){
    int n;
    cin >> n;
    string u = dec_to_bin(n);
    for(int i = u.size()-1;i >= 0; i--){
        cout << u[i];
    }
    return 0;

}