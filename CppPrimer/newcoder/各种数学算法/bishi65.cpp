//分数取模，通过费马小定理把除的模转化为除数的模-2次方求模，然后把式子变形就行
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long fast_pow(long long a,long long b,long long p){
    long long res = 1;
    a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        cout << ((a % P + P) % P* (fast_pow(b,P-2,P))) % P << endl;
    }
    return 0;
    
}