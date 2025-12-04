#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent,sz;
    DSU(int n): parent(n+1),sz(n+1,1){
        for(int i = 1; i<= n; i++) parent[i] = i;
    }

    int find(int x){
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unite(int a,int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return;
    }
    int sizeofx(int x){
        return sz[find(x)];
    }
    bool insameu(int a,int b){
        a = find(a);b = find(b);
        if(a == b) return true;
        else return false;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin >> n >> q;
    DSU bcj(n);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i,j; cin >> i >> j;
            bcj.unite(i,j);
        }
        else if(op == 2){
            int i,j;cin >> i >> j;
            bool flag = bcj.insameu(i,j);
            if(flag) cout << "YES" << endl;
            else cout << "NO" <<endl;
        }
        else if(op == 3){
            int i; cin >> i;
            int res = bcj.sizeofx(i);
            cout << res << endl;
        }
    }
    return 0;
}