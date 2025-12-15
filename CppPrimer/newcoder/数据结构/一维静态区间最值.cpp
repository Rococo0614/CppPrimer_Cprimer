#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
const int LOG = 20;

int n, q;
long long a[MAXN];
long long st_min[MAXN][LOG];
long long st_max[MAXN][LOG];
int lg2[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st_min[i][0] = st_max[i][0] = a[i];
    }

    // 预处理 log
    lg2[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg2[i] = lg2[i / 2] + 1;

    // 建 Sparse Table
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
            st_min[i][k] = min(st_min[i][k - 1],
                                st_min[i + (1 << (k - 1))][k - 1]);
            st_max[i][k] = max(st_max[i][k - 1],
                                st_max[i + (1 << (k - 1))][k - 1]);
        }
    }

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        int k = lg2[r - l + 1];
        if (op == 1) {
            // 区间最小
            cout << min(st_min[l][k],
                        st_min[r - (1 << k) + 1][k]) << '\n';
        } else {
            // 区间最大
            cout << max(st_max[l][k],
                        st_max[r - (1 << k) + 1][k]) << '\n';
        }
    }

    return 0;
}