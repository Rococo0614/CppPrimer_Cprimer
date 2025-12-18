//没啥可说的，就是复杂度上来了
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,T,H;
    cin >> n >> T >> H;
    vector<vector<long long>> dp(T+1,vector<long long>(H+1,0));

    for(int i = 0; i < n; i++){
        int t,h;
        long long a;
        cin >> t >> h >> a;
        for(int j = T; j >= t; j--){
            for(int k = H; k >= h; k--){
                dp[j][k] = max(dp[j][k],dp[j-t][k-h] + a);
            }
        }
    }
    cout << dp[T][H] << endl;
    return 0;
}