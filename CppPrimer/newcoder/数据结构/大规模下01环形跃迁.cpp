//初步看出来的两个思路，第一面对环的时候考虑倍增然后%n,方便处理
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    
    // 为了方便，用 0-based
    // 1. 预处理 next0[i] 表示从 i 出发，按规则跃迁的下一个位置
    vector<int> nxt(n);
    // 复制一倍处理环形
    string s2 = s + s;
    // 队列里存 [i+1, i+m] 范围内的 0 的位置
    deque<int> dq;
    
    // 先处理 i=0 的情况
    for (int j = 1; j <= m; j++) {
        if (s2[j] == '0') {
            dq.push_back(j % n);
        }
    }
    if (dq.empty()) {
        nxt[0] = 1 % n; // i+1
    } else {
        nxt[0] = dq.back(); // 最远的 0
    }
    
    // 滑动窗口
    for (int i = 1; i < n; i++) {
        // 移除离开窗口的 i (上一个窗口的 i+1 对应现在 i 的前一个窗口左边界)
        int out = i; // 注意：窗口是 [i+1, i+m]，离开的是 i
        if (!dq.empty() && dq.front() == out % n) {
            dq.pop_front();
        }
        // 加入新进入的 i+m
        int in = i + m;
        if (s2[in] == '0') {
            dq.push_back(in % n);
        }
        if (dq.empty()) {
            nxt[i] = (i + 1) % n;
        } else {
            nxt[i] = dq.back();
        }
    }
    
    // 2. 倍增表
    const int LOG = 61; // 因为 k <= 1e18 < 2^60
    vector<vector<int>> f(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) {
        f[i][0] = nxt[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            f[i][j] = f[f[i][j-1]][j-1];
        }
    }
    
    // 3. 处理查询
    while (q--) {
        int t;
        ll k;
        cin >> t >> k;
        t--; // 转 0-based
        
        int pos = t;
        for (int j = LOG - 1; j >= 0; j--) {
            if (k >> j & 1) {
                pos = f[pos][j];
            }
        }
        cout << pos + 1 << '\n'; // 转 1-based
    }
    
    return 0;
}