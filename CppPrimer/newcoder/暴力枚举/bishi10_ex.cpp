#include <bits/stdc++.h>
using namespace std;

inline int dist(char a, char b) {
    int d = abs(a - b);
    return min(d, 26 - d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int best = INT_MAX;
    for (int i = 0; i <= m - n; ++i) {
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            cost += dist(s[i + j], t[j]);
            if (cost >= best) break; // 剪枝
        }
        best = min(best, cost);
    }

    cout << best << "\n";
}