#include <bits/stdc++.h>
using namespace std;


struct edges{
    int u,v;
    int value;
};

class DSU{
    public:
    vector<int> parent,sz;
    vector<edges> e;
    DSU(int n) : parent(n+1),sz(n+1,1){
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int a){
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    void unionn(int a, int b){
        a = find(a);b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b]; return;
    }
    void sortedge(void){
        sort(e.begin(),e.end(),[](edges a,edges b){
            return a.value < b.value;
        });
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    DSU bcj(n);
    while(m--){
        int x,y,t; cin >> x >> y >> t;
        bcj.e.push_back({x,y,t});
    }
    bcj.sortedge();
    int res = 0,components = n;
    for(auto& p : bcj.e){
        if(bcj.find(p.u) != bcj.find(p.v)){
            bcj.unionn(p.u,p.v);
            res = p.value;
            components--;
        }
        if(components == 1){
            cout << res << endl;
            return 0;
        };
    }
    cout << -1 << endl;
    return 0;
}