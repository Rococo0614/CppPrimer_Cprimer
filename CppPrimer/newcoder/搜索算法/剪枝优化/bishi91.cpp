//通过一道题体会剪枝的魅力
#include <bits/stdc++.h>
using namespace std;

int m;
int targetlen;
vector<bool> visit;
vector<int> stick_dq;


bool dfs(int curlen,int idx,int num){
    if(num == m) return true;
    if(curlen == targetlen){return dfs(0,0,num + 1);}
    int prev = -1;
    int flag = 0;
    if(curlen != 0) flag = 1;
    for(int i = idx; i < (int) stick_dq.size(); i++){
        if(visit[i]) continue;
        if(curlen + stick_dq[i] > targetlen) continue;
        if(prev == stick_dq[i]) continue;
        int x = curlen + stick_dq[i];
        visit[i] = 1;
        if(dfs(x,i+1,num)) return true;
        visit[i] = 0;
        if(flag == 0) return false;
        prev = stick_dq[i];
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stick_dq.resize(n);
    visit.resize(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {cin >> stick_dq[i]; sum += stick_dq[i];}
    if(n == 1) {cout << stick_dq[0] << endl; return 0;}
    sort(stick_dq.begin(),stick_dq.end(),[](int a,int b){
        return a > b;
    });
    int max_stick = stick_dq[0];
    for(int i = max_stick; i <= sum; i++){
        if(sum % i == 0){
            targetlen = i;
            m = sum / targetlen;
            if(dfs(0,0,0)) {cout << i << endl; return 0;}
        }
    }
    return 0;
}