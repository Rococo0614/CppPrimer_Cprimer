//岛屿连接数量，就是对所有区域尝试使用bfs
//为什么逐行扫描不行？ 你去看看W这个字母，不仅联通，且上下变换，因此不太行;
#include <bits/stdc++.h>
using namespace std;


int N,M;
vector<string> g;
bool vis[110][110];

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

void dfs(int x,int y){
    vis[x][y] = true;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
            if(!vis[nx][ny] && g[nx][ny] == 'W'){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    g.resize(N);
    for(int i = 0; i < N; i++) cin >> g[i];

    int cnt = 0;
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < M ;j++){
            if(!vis[i][j] && g[i][j] == 'W'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}