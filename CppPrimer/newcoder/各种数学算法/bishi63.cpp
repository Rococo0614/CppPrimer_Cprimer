//没什么好说的，主要的思路就是我放的下你要计算的东西，我就先算一次全存着，等你用了直接找就行。
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1000001;
vector<long long> factorial(MAX_N);

void pre_calfactorial(){
    factorial[0] = 1;
    for(int i = 1; i <= MAX_N;i++){
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre_calfactorial();
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << factorial[n] << endl;
    }
    return 0;
}