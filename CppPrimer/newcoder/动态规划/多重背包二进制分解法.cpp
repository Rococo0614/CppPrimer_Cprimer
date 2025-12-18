//有点类似fenwick树，把同组的拆成二进制，减少数量，譬如2个算一组，4个算一组，7个算一组这样就代替了13个一样的
//多重背包还有一种方法是单调队列，这里暂时没看懂
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    int T; cin >> T;
    while(T--){
        int n,m; cin >> n >> m;
        vector<pair<int64,int64>> items;
        for(int i = 0; i < n; i++){
            int w,v,s;
            cin >> w >> v >> s;
            int k = 1;
            while(s >= k){
                items.emplace_back(k*w,k*v);
                s -= k;
                k <<= 1;
            }
            if(s > 0){
                items.emplace_back(s*w, s*v);
            }
        }
        vector<int64> dp(m+1,0);
        for(auto& [cw,cv] : items){
            for(int j = m; j >= cw; j--){
                dp[j] = max(dp[j], dp[j - cw] + cv);
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}