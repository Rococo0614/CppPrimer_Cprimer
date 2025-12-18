//区间动态规划
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<int> w(n + 1);
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            int cost = s[j] - s[i - 1];
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}