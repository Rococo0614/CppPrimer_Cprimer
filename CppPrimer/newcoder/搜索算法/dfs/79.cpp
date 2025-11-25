//动态规划，感觉现在只能欣赏
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    vector<int> valid;
    vector<int> weight;    // 每个 mask 的行权重

    for (int mask = 0; mask < (1 << M); mask++) {
        if (mask & (mask << 1)) continue; // 行内相邻冲突
        valid.push_back(mask);
    }

    for (int mask : valid) {
        int sum = 0;
        for (int j = 0; j < M; j++)
            if (mask & (1 << j))
                sum += a[0][j];
        weight.push_back(sum);
    }

    int S = valid.size();
    vector<vector<int>> dp(N, vector<int>(S, -1));

    for (int i = 0; i < S; i++)
        dp[0][i] = weight[i];

    for (int r = 1; r < N; r++) {
        vector<int> w(S, 0);
        for (int i = 0; i < S; i++) {
            int mask = valid[i];
            int sum = 0;
            for (int j = 0; j < M; j++)
                if (mask & (1 << j))
                    sum += a[r][j];
            w[i] = sum;
        }

        for (int i = 0; i < S; i++) {
            int cur = valid[i];
            for (int k = 0; k < S; k++) {
                int pre = valid[k];

                if (pre & cur) continue;
                if (pre & (cur << 1)) continue;
                if (pre & (cur >> 1)) continue;

                dp[r][i] = max(dp[r][i], dp[r-1][k] + w[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < S; i++)
        ans = max(ans, dp[N-1][i]);

    cout << ans << endl;

    }
    return 0;
    
}
