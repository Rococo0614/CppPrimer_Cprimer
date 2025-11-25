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
        vector<int> q;
        q.reserve(n);
        for(int i = 0; i < n; i++){
            cin >> q[i];
            if(i > 0 && i < n-1 && q[i] == -1){
                q[i] = 0;
            }
        }
        if(q[0] == -1 && q[n-1] == -1){
            q[0] = 0;
            q[n-1] = 0;
        }
        else if(q[0] == -1) q[0] = q[n-1];
        else if(q[n-1] == -1) q[n-1] = q[0];

        int res = abs(q[n-1] - q[0]);
        cout << res << endl;
        for(int i = 0; i < n; i++){
            cout << q[i] << (i == n-1 ? "\n" : " "); 
        }
    }
    return 0;
}