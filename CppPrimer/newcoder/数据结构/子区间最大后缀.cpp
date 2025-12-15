//引入了fenwick树(BIT)，通过lowbit(i) = i & (-i)来维护前缀达到复杂度是logn
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, k, a[MAXN], nxt[MAXN];
int bit[MAXN];

void add(int i, int v) {
    for (; i <= n + 1; i += i & -i) bit[i] += v;
}
int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    // 计算 nxt[i] = i 之后第一个 > a[i] 的位置
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        nxt[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }
    
    // Fenwick 初始化
    for (int i = 1; i <= k; i++) {
        add(nxt[i], 1);
    }
    
    for (int l = 1, r = k; r <= n; l++, r++) {
        // 当前窗口 [l, r] 内，nxt[i] > r 的个数
        int ans = sum(n + 1) - sum(r);
        printf("%d\n", ans);
        // 移动窗口
        add(nxt[l], -1);
        if (r + 1 <= n) add(nxt[r + 1], 1);
    }
    
    return 0;
}