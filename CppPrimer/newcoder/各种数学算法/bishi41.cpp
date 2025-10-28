#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    int i = 1;
    long long sum = 0;
    while(i <= n){
        long long v = n / i;
        long long new_i = n / v + 1;
        sum += (new_i - i ) * v;
        i = new_i;
    }
    cout << sum << endl;
}