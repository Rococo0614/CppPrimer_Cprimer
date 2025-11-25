//快速幂，这玩意跟1+1一样太经典，一眼看不出来是你的问题
#include <bits/stdc++.h>

using namespace std;

long long fast_pow(long long a,long long b,long long p){
    long long res = 1;
    a %= p;
    while(b > 0){
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res % p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long a,b,p;
        cin >> a >> b >> p;
        cout << fast_pow(a,b,p) << endl;
    }
}