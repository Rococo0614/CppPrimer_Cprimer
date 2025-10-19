#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
目标：
给定有向图，对节点进行黑白染色。
核心边：黑 -> 白
要求找到一种染色，使核心边数量 >= m/4 + 1
方法：
1. 初始贪心：按 (出度 - 入度) 排序，前半白，后半黑。
2. 贪心改进：不断翻转某个节点颜色，若能增加核心边数则接受。
*/

//其实这道题用随机数构造就行.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        // 图存储：pair(v, 边编号)
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<int> inreg(n + 1, 0), outreg(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            outreg[u]++;
            inreg[v]++;
        }

        // 节点评分
        vector<int> score(n + 1);
        for (int i = 1; i <= n; i++) {
            score[i] = outreg[i] - inreg[i];
        }

        // 按分数从大到小排序节点编号
        vector<int> node(n);
        iota(node.begin(), node.end(), 1);
        sort(node.begin(), node.end(), [&](int a, int b) {
            return score[a] > score[b];
        });

        // 初始贪心染色：前半白(0)，后半黑(1)
        vector<int> color(n + 1, 0);
        int half = n / 2;
        for (int i = 0; i < n; i++) {
            if (i < half) color[node[i]] = 0;  // 白
            else color[node[i]] = 1;           // 黑
        }

        // 函数：统计当前核心边数量
        auto count_core_edges = [&](vector<int> &color) {
            int cnt = 0;
            for (int u = 1; u <= n; u++) {
                for (auto [v, id] : adj[u]) {
                    if (color[u] == 1 && color[v] == 0)
                        cnt++;
                }
            }
            return cnt;
        };

        // 计算初始核心边数
        int core_cnt = count_core_edges(color);

        // 贪心改进：尝试翻转节点颜色以增加核心边数
        bool improved = true;
        while (improved) {
            improved = false;
            for (int u = 1; u <= n; u++) {
                int before = 0, after = 0;

                // 当前节点对核心边数量的贡献
                for (auto [v, id] : adj[u]) {
                    if (color[u] == 1 && color[v] == 0) before++;
                    if (color[u] == 0 && color[v] == 1) before--;
                }
                for (int x = 1; x <= n; x++) {
                    for (auto [v, id] : adj[x]) {
                        if (v == u) {
                            if (color[x] == 1 && color[u] == 0) before++;
                            if (color[x] == 0 && color[u] == 1) before--;
                        }
                    }
                }

                // 翻转颜色后，重新计算该点的贡献
                int new_color = 1 - color[u];
                for (auto [v, id] : adj[u]) {
                    if (new_color == 1 && color[v] == 0) after++;
                    if (new_color == 0 && color[v] == 1) after--;
                }
                for (int x = 1; x <= n; x++) {
                    for (auto [v, id] : adj[x]) {
                        if (v == u) {
                            if (color[x] == 1 && new_color == 0) after++;
                            if (color[x] == 0 && new_color == 1) after--;
                        }
                    }
                }

                // 如果翻转能提高核心边数，就执行
                if (after > before) {
                    color[u] = new_color;
                    improved = true;
                }
            }
        }

        // 再次统计最终核心边
        core_cnt = count_core_edges(color);

        // 输出结果
        if (core_cnt >= m / 4 + 1) {
            vector<int> core_edges;
            for (int u = 1; u <= n; u++) {
                for (auto [v, id] : adj[u]) {
                    if (color[u] == 1 && color[v] == 0) {
                        core_edges.push_back(id);
                    }
                }
            }

            cout << core_edges.size() << "\n";
            sort(core_edges.begin(), core_edges.end());
            for (int id : core_edges) cout << id << " ";
            cout << "\n";
        } else {
            cout << "No valid core edges.\n";
        }
    }

    return 0;
}