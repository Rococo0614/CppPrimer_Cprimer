//双循环就是在内部看在有i件的情况下最大是多少，外部遍历完就是所有m件都能用的情况下最大是多少
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n,m; cin >> n >> m;
        vector<int> w(n),v(n);
        for(int i = 0; i < n; i++){
            cin >> w[i] >> v[i];
        }
        vector<int> dp(m+1,0);
        for(int i = 0; i < n; i++){
            for(int j = w[i]; j <= m; j++){
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}