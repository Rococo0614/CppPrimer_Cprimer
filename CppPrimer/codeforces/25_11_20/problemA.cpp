#include <iostream>
using namespace std;

int calallcon(int n){
    if(n == 0 || n % 2 != 0) return 0;
    int cow = n / 4;
    return cow + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int legs;
        cin >> legs;
        cout << calallcon(legs) << endl;
    }
    return 0;
}