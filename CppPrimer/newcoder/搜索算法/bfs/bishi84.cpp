//这道题让你能够清楚理解bfs的结构，外层的for循环是做什么用，以及内部应该如何做分析；
#include <bits/stdc++.h>
using namespace std;

const int dx[6] = {1, -1, 10, -10, 100, -100};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dist(301, -1);
    vector<bool> vis(301, false);

    queue<int> q;
    dist[10] = 0;
    vis[10] = true;
    q.push(10);
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int dp = d + dx[i];
            if (dp >= 10 && dp <= 300 && !vis[dp]) {
                dist[dp] = dist[d] + 1;
                vis[dp] = true;
                q.push(dp);
            }
        }
        if (!vis[300]) {
            dist[300] = 1;
            vis[300] = true;
            q.push(300);
        }
    }


    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dist[a] + dist[b] + dist[c] + dist[d] << endl;
    }
    return 0;

}