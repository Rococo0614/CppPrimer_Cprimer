#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u,v;
    int value;
};

class DSU{
    public:
    vector<int> parent,sz;
    DSU(int n): parent(n+1),sz(n+1,1){
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int a){
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    void cunion(int a,int b){
        a = find(a);b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        parent[b] = a;
        return;
    }
    bool ifunion(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        else return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    DSU check(n);vector<edge> edges(m);
    int cnt = n-1;
    for(int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        edges[i].u = u;edges[i].v = v;
        edges[i].value = w;
        if(check.ifunion(u,v)){
            check.cunion(u,v);
            cnt--;
        }
    }
    if(cnt != 0){
        cout << "NO" << endl;
        return 0;
    }
    sort(edges.begin(),edges.end(),[](const edge& a,const edge& b){
        return a.value < b.value;
    });

    DSU res(n);long long ans = 0;cnt = n-1;
    for(int i = 0; i < m ;i++){
        if(res.ifunion(edges[i].u,edges[i].v)){
            res.cunion(edges[i].u,edges[i].v);
            ans += edges[i].value;
            cnt--;
        }
        if(cnt == 0) break;
    }
    cout << ans << endl;
    return 0;

}