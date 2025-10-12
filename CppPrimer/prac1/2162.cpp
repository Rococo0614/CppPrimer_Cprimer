#include <iostream>
using namespace std;

int main(){
    string in;
    cin >> in;
    int x = 1,sum  = 0;
    for(int i = in.size() - 1; i >= 0; i--){
        if(in[i] == '1'){
            sum += x;
        }
        x *= 2;
    }
    cout << sum;
    return 0;
}