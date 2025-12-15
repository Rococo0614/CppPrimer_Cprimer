#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    deque<int> q;
    vector<int> ans;

    for(int i = 1; i <= n; i++){
        if(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] <= a[i]){
            q.pop_back();
        }

        q.push_back(i);

        if(i >= k){
            ans.push_back(a[q.front()]);
        }
    }

    for(int& i : ans){
        cout << i << " ";
    }
    return 0;


}