#include <bits/stdc++.h>
using namespace std;

class BSU{
    public:
    vector<int> parent,sz,value,price;
    BSU(int n):parent(n+1),sz(n+1,1),value(n+1),price(n+1){
        for(int i = 1; i<= n; i++) parent[i] = i;
    }
    int find(int x){
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unionn(int a,int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,w;cin >> n >> m >>w;
    BSU bcj(n);
    for(int i = 1; i <= n; i++){
        int c,d; cin >> c >> d;
        bcj.price[i] = c;
        bcj.value[i] = d;
    }
    while(m--){
        int u,v; cin >> u >> v;
        bcj.unionn(u,v);
    }

    vector<int> sumPrice(n+1,0),sumValue(n+1,0);
    for(int i = 1; i <=n ; i++){
        int r = bcj.find(i);
        sumPrice[r] += bcj.price[i];
        sumValue[r] += bcj.value[i];
    }

    vector<int> dp(w+1,0);
    for(int r = 1; r <=n ;r++){
        if(sumValue[r] == 0) continue;
        int cost = sumPrice[r];
        int value = sumValue[r];
        for(int p = w; p >= cost; p--){
            dp[p] = max(dp[p],dp[p-cost] + value);
        }
    }

    int ans = 0;
    for(int i = 0; i <=w; i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}