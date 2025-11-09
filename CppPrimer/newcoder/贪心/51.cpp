#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    priority_queue<int, vector<int>, greater<int>> minHeap;
    ll profit = 0;
    for(int i = 0; i < n; i++){
        minHeap.push(p[i]);
        if(p[i] > minHeap.top() && !minHeap.empty()){
            profit += p[i] - minHeap.top();
            minHeap.pop();
            minHeap.push(p[i]);
        }
    }

    cout << profit << endl;
    return 0;

}