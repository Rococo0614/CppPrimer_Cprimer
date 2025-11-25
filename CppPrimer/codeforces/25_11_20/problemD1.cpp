#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
           int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    set<int> S;
    vector<pair<int,int>> edges;
    S.insert(p[0]); // 第一节点单独放进去

    for(int k = 1; k < n; k++){
        int v = p[k];

        auto it = S.lower_bound(v);
        if(it == S.begin()){
            // 没有比 v 小的，无法连通
            cout << "No\n";
            return 0;
        }
        --it;                // it 指向最大的小于 v 的点
        int x = *it;

        edges.push_back({x, v});
        S.insert(v);
    }

    cout << "Yes\n";
    // for(auto &e : edges){
    //     cout << e.first << " " << e.second << "\n";
    // }
    }
    return 0;
}
