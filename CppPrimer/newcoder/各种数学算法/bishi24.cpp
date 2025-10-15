//考虑式子变形，原式子等价于a_i - i == a_j - j,将输入所有的数组都进行该计算key = a_k - k并统计个数cnt，那么相同的key有C(cnt,2)中组合方式

#include <iostream>
#include <map>

using namespace std;

int main(){
    int num;
    cin >> num;
    map<int,int> cnt;
    for(int i = 0; i < num; i++){
        int a;
        cin >> a;
        int key = a - i - 1;
        cnt[key]++;
    }

    long long ans = 0;
    for(auto &p : cnt){
        long long n = p.second;
        if(n  >= 2){
            ans += (n-1)*n / 2;
        }
    }
    cout << ans << endl;
    return 0;
}