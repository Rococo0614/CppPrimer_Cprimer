#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    const int max_a = 1000000;
    vector<int> freq_b(max_a+5, 0);
    for(int x : b) freq_b[x]++;

    vector<int> freq_c(max_a+5,0);
    int match = 0;
    int ans = 0;

    for(int i = 0; i < m; i++){
        int v = a[i];
        if(freq_c[v] < freq_b[v]) match++;
        freq_c[v]++;
    }

    if(match >= k) ans++;

    for(int i = m; i < n; i++){
        int v_out = a[i-m];
        if(freq_c[v_out] <= freq_b[v_out]) match--;
        freq_c[v_out]--;

        int v_in = a[i];
        if(freq_c[v_in] < freq_b[v_in]) match++;
        freq_c[v_in]++;

        if(match >= k) ans++;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}