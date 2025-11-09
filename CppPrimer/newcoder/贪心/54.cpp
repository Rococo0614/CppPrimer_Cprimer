#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i128 = __int128_t;

class Goods{
    public:
    ll w;
    ll v;
    ll c;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Goods> goods(n);
    for(int i = 0; i < n; i++){
        cin >> goods[i].w >> goods[i].v >> goods[i].c;
    }
    sort(goods.begin(),goods.end(),[](const auto &a, const auto &b){
        return a.c * b.w < b.c * a.w;
    });
    i128 all_v = 0;
    i128 M = 0;
    for(int i = 0; i < n; i++){
        all_v += (goods[i].v - goods[i].c * M);
        M += goods[i].w;
    }
    cout << (ll)all_v << endl;
    return 0;

}