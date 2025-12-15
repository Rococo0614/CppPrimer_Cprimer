//如果我需要对一个数组中每次只改部分，但是最后需要所有的数值出现结果，我该如何做？
//通过使用构建差分数组，然后求前缀和并加上基础数组就ok
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

vector<int64> cmp(vector<int64>& a){
    for(int i = 2; i < a.size(); i++){
        a[i] += a[i-1];
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<int64> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int64> diff(n+1);
    while(m--){
        int l,r,k; cin >> l >> r >> k;
        diff[l] += k;
        diff[r+1] -= k;
    }
    cmp(diff);
    for(int i = 1; i < a.size(); i++){
        cout << a[i] + diff[i] << " ";
    }
    return 0;

}