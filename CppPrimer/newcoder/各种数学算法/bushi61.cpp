#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(ll n){
    ll i = __builtin_popcountll(n);
    ll q = (1ll<<i) - 1;
    cout << i << " " << q << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}