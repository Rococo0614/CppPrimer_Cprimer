#include <iostream>
using namespace std;

int main(){
 long long num;
    cin >> num ;
    while(num > 10){
        cout << num % 10 << " ";
        num = num / 10;
    }
    cout << num % 10 << endl;
    return 0;
}