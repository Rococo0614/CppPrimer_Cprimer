//二维差分对于边界的观察需要更准确，一维差分数组理论上也需要再扩充一轮，但是可以忽略，因为不会对计算产生影响
//但是二维差分对边界的检查非常严格，所以会有影响
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

void prefix(vector<vector<int64>>& a){
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < a[0].size(); j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int64>> a(n+1, vector<int64>(m+1));
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < a[0].size(); j++){
            cin >> a[i][j];
        }
    }
    
    vector<vector<int64>> diff(n+2, vector<int64>(m+2));
    while(q--){
        int x1,y1,x2,y2,k; cin >> x1 >> y1 >> x2 >> y2 >> k;
        diff[x1][y1] += k;
        diff[x1][y2+1] -= k;
        diff[x2+1][y1] -= k;
        diff[x2+1][y2+1] += k;
        
    }
    prefix(diff);
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < a[0].size(); j++){
            cout << a[i][j] + diff[i][j] << (j == a[0].size()-1 ? "\n" : " ");
        }
    }
    return 0;
    
}