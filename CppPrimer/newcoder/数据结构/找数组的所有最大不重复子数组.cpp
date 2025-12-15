#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    unordered_map<int,int> pos;
    int left = 1, max_len = 0;
    vector<pair<int,int>> ans;

    for(int right = 1; right <= n; right++){
        if(pos.count(a[right]) && pos[a[right]] >= left){
            left = pos[a[right]] + 1;
        }
        pos[a[right]] = right;


        int cur_len = right - left + 1;
        if(cur_len > max_len){
            max_len = cur_len;
            ans.clear();
            ans.emplace_back(left,right);
        }else if(cur_len == max_len){
            ans.emplace_back(left,right);
            }
    }
    cout << ans.size() << endl;
    for(auto& [l,r] : ans){
        cout << l << " " << r << endl;
    }
    return 0;


}