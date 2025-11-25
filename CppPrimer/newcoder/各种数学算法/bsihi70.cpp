//相当于前面数学算法的一个集合，还是注意并不是你算起来不会出现负数就不会取模负，存在乘积溢出的问题
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const int N = 500000;
long long fast_pow(long long a,long long b, long long p){
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

vector<long long> pre_cal_factorial(){
    vector<long long> fac(N+1,1);
    for(int i = 1; i <= N; i++){
        fac[i] = fac[i-1] * i % P;
    }
    return fac;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<long long> fac = pre_cal_factorial();
    vector<long long> inv_fac(N+1,1);
    for(int i = 1; i <= N; i++){
        inv_fac[i] = fast_pow(fac[i], P-2, P);
    }
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        long long res = (fac[m] * inv_fac[n] % P * inv_fac[m-n] % P) % P;
        res = (res + P) % P;
        cout << res << endl;
    }
    return 0;
}