//头一回系统总结bfs吧，感觉其实有点想光的传播，他是四个方向，我可以创建一个矩阵统计到达这个点的最短步数是多少，然后
//这个队列是神来之笔，他通过先入先出去经过一次循环统计出所有下一轮需要传播点
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    int xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];   // 0=可走，1=障碍

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Node> q;

    // 起点
    if (grid[xs-1][ys-1] == '.') {
        dist[xs-1][ys-1] = 0;
        q.push({xs-1, ys-1});
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 越界或障碍
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*')
                continue;

            // 没访问过
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[xt-1][yt-1] << endl; // -1 表示不可达
    return 0;
}