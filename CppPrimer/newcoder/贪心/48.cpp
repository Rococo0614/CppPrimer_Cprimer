#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int win_idx = n-1,win_len = 2;
    long long score = 0;
    while(win_idx > 0){
        if(a[win_idx] - a[win_idx - 1] <= k){
            score += (long long)a[win_idx] * a[win_idx - 1];
            win_idx -= win_len;
        } 
        else{
            win_idx--;
        }
    }
    cout << score << endl;
    return 0;
}