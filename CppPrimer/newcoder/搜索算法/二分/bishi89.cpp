//原始人学会了钻木取火，接下来就该知道怎么用打火机了，直接用upper_bound去找值就行
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> P;

vector<ll> prefix_S(vector<int> P){
    vector<ll> S(n,0);
    S[0] = P[0];
    for(int i = 1; i < n; i++){
        S[i] = S[i-1] + P[i];
    }
    return S;
} 

vector<double> prefix_T(vector<ll> S){
    vector<double> T(n-2,0.0);
    for(int i = 0; i < n-2; i++){
        if(2*S[i] >= (S[i]+S[n-1]) / 2.0){
            T[i] = 2*S[i];
        }
        else{
            T[i] = (S[i] + S[n-1]) / 2; 
        }
    }
    return T;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    P.resize(n);
    for(int i = 0; i < n; i++){
        cin >> P[i];
    }
    vector<ll> S = prefix_S(P);
    vector<double> T = prefix_T(S);

    ll cnt = 0;
    for(int i = 0; i < n-2; i++){
        int l = i+1, r = n-2;
        int pos = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(S[mid] > T[i]){
                pos = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(pos != -1) cnt += n - 1 - pos;
    }

    cout << cnt << endl;
    return 0;
}