//有一说一，没看懂
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
const int LOG = 20; // 因为 2^19 > 5e5

int N, M, R;
vector<int> G[MAXN];
int fa[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int parent) {
    fa[u][0] = parent;
    depth[u] = depth[parent] + 1;

    for (int v : G[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // 1. 把 u 提到和 v 同一深度
    for (int k = LOG - 1; k >= 0; --k) {
        if (depth[fa[u][k]] >= depth[v]) {
            u = fa[u][k];
        }
    }

    if (u == v) return u;

    // 2. 同时往上跳
    for (int k = LOG - 1; k >= 0; --k) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }

    // 3. 父节点就是 LCA
    return fa[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    for (int i = 1; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // 根的父亲设为 0（深度 0）
    depth[0] = 0;
    dfs(R, 0);

    // 预处理倍增表
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= N; ++i) {
            fa[i][k] = fa[ fa[i][k - 1] ][k - 1];
        }
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}