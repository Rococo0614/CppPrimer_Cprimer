//当年能想出来这个的家里得请高人了
#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i < n; i++){
        if(s[i]==s[pi[i-1]]) {pi[i] = pi[i-1] + 1;}
        else{
            int j = pi[i-1];
            while(s[i] != s[j] && j > 0){
                j = pi[j-1];
                if(s[i] == s[j]) {
                    j++;
                    pi[i] = j;
                    break;
                }
            }

        }
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ans = kmp(s);
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i == n-1 ? "\n" : " ");
        }
    }
    return 0;
}
