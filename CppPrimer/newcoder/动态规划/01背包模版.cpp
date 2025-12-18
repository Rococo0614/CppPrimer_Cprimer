//对于严格要求装满，或者其他边界条件，需要的是对除了该条件下其他状态都设置为不可达，然后通过状态转移来进行
//在只选一次的情况下，01背包的倒着来有点像避免前缀和，如果从小到大更新是更新完可能会直接用，导致某个高价值会被选取多次
#include <bits/stdc++.h>
using namespace std;

struct object {
    int value;
    int volume;
};

int solution1(vector<object>& obj, int& V) {
    int n = obj.size() - 1;
    vector<int> dp(V + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= obj[i].volume; j--) {
            dp[j] = max(dp[j], dp[j - obj[i].volume] + obj[i].value);
        }
    }
    return dp[V];
}

int solution2(vector<object>& obj, int& V) {
    int n = obj.size() - 1;
    vector<int> dp(V + 1, INT_MIN);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= obj[i].volume; j--) {
            if (dp[j - obj[i].volume] != INT_MIN) {
                dp[j] = max(dp[j], dp[j - obj[i].volume] + obj[i].value);
            }
        }
    }
    return (dp[V] == INT_MIN) ? 0 : dp[V];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, V;
    cin >> n >> V;
    vector<object> obj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> obj[i].volume >> obj[i].value;
    }
    int ans1 = solution1(obj, V);
    int ans2 = solution2(obj, V);
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}