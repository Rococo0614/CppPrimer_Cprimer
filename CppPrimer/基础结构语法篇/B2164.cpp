#include <iostream>
using namespace std;

long long jc(int n){
    long long sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    return sum;
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << (jc(n)/(jc(m)*jc(n-m))) % int (10e9+7);
    return 0;
    
}