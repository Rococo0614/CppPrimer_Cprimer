//bfs的精髓就在这个队列的引入，请细细体会
#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
vector<string> g;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    vis.assign(n, vector<bool>(m, false));

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '*' && !vis[i][j]) {
                queue<pair<int, int>> q;
                q.push({i,j});
                vis[i][j] = true;

                int area = 0;
                int lmin = i, wmin = j;
                int lmax = i, wmax = j;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    area++;
                    lmin = min(x, lmin);
                    lmax = max(x, lmax);
                    wmin = min(y, wmin);
                    wmax = max(y, wmax);

                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (g[nx][ny] == '.' && !vis[nx][ny]) {
                                q.push({nx, ny});
                                vis[nx][ny] = true;
                            }
                        } else {
                            continue;
                        }
                    }
                }

                int length = lmax - lmin + 1;
                int width = wmax - wmin + 1;
                if (area == length * width) ans++;

                }

        }
    }
    cout << ans << endl;
    return 0;

}