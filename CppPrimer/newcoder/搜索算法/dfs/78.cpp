//这里也用dfs，核心思想就是字典序的顺序
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10];
bool vis[10];

void dfs(int pos){
    if(pos == n){
        for(int i = 0; i < n; i++){
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
        return;
    }

    for(int x = 1; x <= n; x++){
        if(!vis[x]){
            vis[x] = true;
            a[pos] = x;
            dfs(pos+1);
            vis[x] = false;
        }

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(0);
}