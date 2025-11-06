#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    if(!(cin >> n >> m >> k)) return 0;
    vector<vector<char>> chess(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> chess[i][j];
        }
    }

    vector<int> segments;
    for(int i = 0; i < m; i++){
        int len = 0;
        for(int j = 0; j < n; j++){
            if(chess[j][i] == 'o'){
                len++;
            }
            else{
                if(len > 0){
                segments.push_back(len);
                len = 0;
                }
            }
        }
        if(len > 0){
            segments.push_back(len);
        }
    }
    sort(segments.rbegin(),segments.rend());
    int used = 0, score = 0;
    for(int L : segments){
        if(used >= k) break;
        int can_paint = min(L, k - used);
        score += max(0,can_paint - 1);
        used += can_paint;
    }
    cout << score << endl;
    return 0;
}