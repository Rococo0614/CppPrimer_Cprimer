//如果你想要求在两个数组之间都影响比较大的排序，那就尝试两个数组的影响做综合，这个思路是最基础的吧
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long suma = accumulate(a.begin(), a.end(), 0LL);
    long long sumb = accumulate(b.begin(), b.end(), 0LL);

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    // 用 a[i] + b[i] 排序
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return (a[i] + b[i]) > (a[j] + b[j]);
    });

    long long cura = 0, curb = 0;
    int k = 0;
    vector<int> ans;
    for (int i : idx) {
        cura += a[i];
        curb += b[i];
        ans.push_back(i + 1);
        k++;
        if (2 * cura > suma && 2 * curb > sumb) break;
    }

    cout << k << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}