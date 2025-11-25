//二分是个人都会，但是你的知道什么时候用更合适？ 以及如何从一道题里面看出来二分怎么用？ 从最简单的折半查找
//到一定循环就能完成目标的非整数计算，再到左右判断的while循环，需要很多题才能熟练掌握
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll m;

bool isok(ll x,vector<ll> c){
    ll sum = 0;
    for(ll ci : c){
        if(x > ci) sum += x-ci;
        if(sum > x && sum > m) return false;
    }
    return (sum <= x && sum <= m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    ll l = 0, r = 1e9;
    ll ans = 0;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(isok(mid,c)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << endl;
    return 0;
}