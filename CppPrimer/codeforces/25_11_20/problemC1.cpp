#include <bits/stdc++.h>
using namespace std;

// 返回 1: 先手(奇轮)赢, 2: 后手(偶轮)赢, 0: 平局
int solve_winner(const vector<long long>& a, const vector<long long>& b){
    int n = (int)a.size();
    long long A = 0, B = 0;
    for(int i=0;i<n;i++){ A ^= a[i]; B ^= b[i]; }
    if(A == B) return 0; // 平局

    long long X = A ^ B;
    int p = 63 - __builtin_clzll(X); // 64-bit，找到最高位索引（0-based）
    // 找最大的下标 j (1-based) 使得 (a_j ^ b_j) 在位 p 为 1
    int j = -1;
    for(int i = n-1; i >= 0; --i){
        if( ((a[i] ^ b[i]) >> p) & 1LL ){
            j = i + 1; // 1-based index
            break;
        }
    }
    if(j == -1){
        // 没有 t_i 在位 p 为 1，S_p 恒为 0，按初始 A,B 的位判断
        int bitA = (A >> p) & 1LL;
        if(bitA == 1) return 1;
        else return 2;
    } else {
        // j 存在，掌控者赢
        if( j % 2 == 1 ) return 1; // 奇数下标 -> 先手
        else return 2; // 偶数下标 -> 后手
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
            int n;
    if(!(cin >> n)) return 0;
    vector<long long> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int res = solve_winner(a,b);
    if(res == 0) cout << "Tie\n";
    else if(res == 1) cout << "Ajisai\n";
    else cout << "Mai\n";
        
    }
    return 0;
}
