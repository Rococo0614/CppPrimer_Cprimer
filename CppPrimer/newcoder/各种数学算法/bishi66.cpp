//要做到训练有素，首先判断如果直接查找乘的计算复杂度，按照之前的经验进行复杂度归纳
//其次看到能够对数据进行预处理并通过四则运算就能解决问题的情况，要敏锐注意到，可以通过数据预处理显著降低运算量
//最后牢记计算机中没有除法，如果我们要使用对大数的除法务必三思，往往最优解都是用快速幂和费马小定理算

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long fast_pow_mod(long long a, long long b, long long p){
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1; 
    }
    return res;
}

vector<long long> prefix_multi_mod(vector<int> arr){
    int size = arr.size();
    vector<long long> res(size,1);
    for(int i = 1; i < size; i++){
        res[i] = (res[i-1] % MOD) * (arr[i] % MOD) % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<long long> pre_mul = prefix_multi_mod(arr);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (pre_mul[r] * fast_pow_mod(pre_mul[l-1],MOD - 2, MOD)) % MOD << " ";
    }
    return 0;


}