#include <bits/stdc++.h>
using namespace std;

struct Build {
    long long t, d;
};

int main() {
    int n;
    cin >> n;
    vector<Build> builds(n);
    for (int i = 0; i < n; ++i) cin >> builds[i].t >> builds[i].d;

    sort(builds.begin(), builds.end(), [](auto &a, auto &b){
        return a.d < b.d;
    });

    priority_queue<long long> pq; // 大顶堆
    long long total_time = 0;
    for (auto &b : builds) {
        pq.push(b.t);
        total_time += b.t;
        if (total_time > b.d) {
            total_time -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << endl;
}