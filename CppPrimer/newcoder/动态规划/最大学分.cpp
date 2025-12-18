//带前后关系的动态规划
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> s;
vector<vector<int>> adj;
vector<vector<long long>> dp;
vector<int> sz; // 记录子树大小

void dfs(int u) {
    // 必须选当前课程u
    dp[u][1] = s[u];
    sz[u] = 1;

    for (int v : adj[u]) {
        dfs(v);
        // 将子树v的DP结果合并到u上 (分组背包)
        for (int j = min(m + 1, sz[u]); j >= 1; --j) {
            for (int k = 1; k <= sz[v] && j + k <= m + 1; ++k) {
                if (dp[u][j] != -1 && dp[v][k] != -1) {
                    dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[v][k]);
                }
            }
        }
        sz[u] += sz[v];
    }
}

int main() {
    cin >> n >> m;
    s.resize(n + 1, 0);
    adj.resize(n + 1);
    dp.assign(n + 1, vector<long long>(m + 2, -1));
    sz.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p >> s[i];
        adj[p].push_back(i); // p=0时，连接到超级根
    }

    dfs(0);

    long long max_credits = dp[0][m + 1];
    cout << (max_credits == -1 ? 0 : max_credits) << endl;

    return 0;
}