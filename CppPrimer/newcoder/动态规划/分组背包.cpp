//本质想法还是考虑二维背包，但是可以做到一维优化
//顺带一提，emplace_back才是现在常用的容器末尾添加
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, M;
    cin >> n >> M;
    vector<vector<pair<int, ll>>> groups(101); // 组号 1~100
    for (int i = 0; i < n; i++) {
        int w, g;
        ll v;
        cin >> w >> v >> g;
        groups[g].emplace_back(w, v);
    }
    
    vector<ll> dp(M + 1, 0);
    for (int g = 1; g <= 100; g++) {
        if (groups[g].empty()) continue;
        vector<ll> last = dp; // 上一组的结果
        for (auto [w, v] : groups[g]) {
            for (int j = M; j >= w; j--) {
                // 用上一组的状态更新当前组的选择
                dp[j] = max(dp[j], last[j - w] + v);
            }
        }
    }
    
    cout << dp[M] << endl;
    
    return 0;
}