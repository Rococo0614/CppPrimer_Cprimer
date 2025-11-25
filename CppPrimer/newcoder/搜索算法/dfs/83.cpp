//通过这道题看明白dfs如果想存储路径该怎么办，以及如何进行合理的dfs写，弄明白dfs的原理，搜索算法这快就难不倒你了;
#include <bits/stdc++.h>
using namespace std;

int h,w;
vector<vector<bool>> vis;
vector<vector<int>> g;
vector<pair<int, int>> path;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

bool dfs(int x, int y){
    vis[x][y] = true;
    path.push_back({x,y});
    if(x == h-1 && y == w-1) return true;

    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx>=0 && nx < h && ny >=0 && ny < w && g[nx][ny] == 0 && !vis[nx][ny]){
            if(dfs(nx,ny)) return true;
        }
    }
    path.pop_back();
    return false;
}

int main(){
    cin >> h >> w;
    g.assign(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> g[i][j];
        }
    } 
    vis.assign(h,vector<bool>(w,false));

    dfs(0,0);
    for(auto [x,y] : path){
        cout << "(" << x << "," << y << ")" << endl;
    }
    return 0;


}
