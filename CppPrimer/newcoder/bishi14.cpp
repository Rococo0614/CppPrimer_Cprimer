#include <iostream>
#include <string>

using namespace std;

int main(){
    string num;
    cin >> num;
    int a  = num[0] - '0';
    int b1 = num[1] - '0';
    int bin = num.size();
    if(b1 >= 5){
        b1 = 0;
        a++;
        if(a == 10){
            a = 1;
            b1 = 0;
            bin++;
        }
    }
    else{
        b1 = 0;
    }
    cout << a << "." << b1 << "*10^" << bin - 1<< endl;
    return 0;
}