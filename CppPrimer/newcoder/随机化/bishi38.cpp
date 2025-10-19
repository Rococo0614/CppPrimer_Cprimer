#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> edges(m + 1);
        vector<vector<int>> adj(n + 1);

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
            adj[u].push_back(v);
        }

        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        // 尝试多次随机染色
        const int MAX_TRY = 2000;
        bool found = false;
        for (int t = 0; t < MAX_TRY; t++) {
            vector<int> color(n + 1);
            for (int i = 1; i <= n; i++)
                color[i] = rng() % 2;  // 随机 0/1 染色

            vector<int> core_edges;
            for (int i = 1; i <= m; i++) {
                auto [u, v] = edges[i];
                if (color[u] == 1 && color[v] == 0)
                    core_edges.push_back(i);
            }

            if ((int)core_edges.size() >= m / 4 + 1) {
                cout << core_edges.size() << "\n";
                for (int id : core_edges) cout << id << " ";
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No valid coloring found.\n";
        }
    }
    return 0;
}