//反向的思维
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

static const long long INF = (1LL<<62);

// Dijkstra：从源点 s 出发，返回 dist 数组
static vector<long long> dijkstra(int n, const vector<vector<pair<int,int>>>& g, int s) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            long long nd = d + w;
            if (nd < dist[v]) { dist[v] = nd; pq.push({nd, v}); }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int,int>>> g(n + 1), gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    auto d_to = dijkstra(n, g, 1);
    auto d_from = dijkstra(n, gr, 1); // 反图上从 1 出发 => 原图上到 1 的最短路

    long long ans = 0;
    for (int v = 2; v <= n; ++v) ans += d_to[v] + d_from[v];
    cout << ans << '\n';
    return 0;
}
