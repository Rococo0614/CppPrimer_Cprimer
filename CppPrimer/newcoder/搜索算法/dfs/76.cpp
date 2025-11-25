//最简答的dfs。只需要输出结果是我能不能从起点走到终点
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> g;
bool vis[110][110];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    queue<pair<int,int>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << "Yes\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {        // 唯一的“嵌套”
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    cout << "No\n";
    return 0;
}
