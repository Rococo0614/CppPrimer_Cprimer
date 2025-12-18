//树形动态规划，不能同时选取一个根和他的节点
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;
vector<vector<int>> adj;
vector<vector<long long>> dp;

void dfs(int u, int p) {
    // 状态初始化
    dp[u][1] = w[u-1]; // 邀请u，获得其气氛值
    dp[u][0] = 0;      // 不邀请u，初始气氛值为0

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        // 累加来自子树的贡献
        dp[u][0] += max(dp[v][0], dp[v][1]); // u不来，v可来可不来
        dp[u][1] += dp[v][0];                // u来了，v一定不能来
    }
}

int main() {
    int n;
    cin >> n;

    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // n=1 是特殊情况，没有边
    if (n == 1) {
        cout << w[0] << endl;
        return 0;
    }

    adj.resize(n + 1);
    vector<bool> has_parent(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
        int boss, subordinate;
        cin >> boss >> subordinate;
        adj[boss].push_back(subordinate);
        adj[subordinate].push_back(boss);
        has_parent[subordinate] = true;
    }

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (!has_parent[i]) {
            root = i;
            break;
        }
    }

    dp.assign(n + 1, vector<long long>(2, 0));
    dfs(root, -1);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
