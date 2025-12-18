//网格动态规划
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> coins(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> coins[i][j];
        }
    }

    int k;
    cin >> k;
    vector<vector<int>> wall_time(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < k; ++i) {
        int r, c, t;
        cin >> r >> c >> t;
        wall_time[r][c] = t;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -INF));

    // Base case: (1, 1)
    dp[1][1] = coins[1][1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;

            // 检查当前格子是否可达
            int arrival_time = i + j - 2;
            if (arrival_time >= wall_time[i][j]) {
                continue; // 此格子无法进入
            }

            long long from_up = -INF;
            if (i > 1 && dp[i - 1][j] != -INF) {
                from_up = dp[i - 1][j];
            }

            long long from_left = -INF;
            if (j > 1 && dp[i][j - 1] != -INF) {
                from_left = dp[i][j - 1];
            }

            long long prev_max = max(from_up, from_left);
            if (prev_max != -INF) {
                dp[i][j] = prev_max + coins[i][j];
            }
        }
    }

    long long max_coins = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            max_coins = max(max_coins, dp[i][j]);
        }
    }

    cout << max_coins << endl;

    return 0;
}
