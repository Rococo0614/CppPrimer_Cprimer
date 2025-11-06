#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    priority_queue<long long> pq;
    long long total = 0;

    for (int i = n - 1; i >= 0; --i) {
        pq.push(a[i]);
        total += a[i];
        if (i % k == 0 && !pq.empty() && i != 0) {
            total -= pq.top();
            pq.pop();
        }
    }


    cout << total << "\n";
    return 0;
}