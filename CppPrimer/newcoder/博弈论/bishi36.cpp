//博弈论至少目前来看，跟计算机程序关系不大，更多的是数学思维，由于两方都会使用最优策略，
//最重要的是学习到这一种思维，从最后（最简单的状态开始）逐步推导出正确的情况。
#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,l,r;
        cin >> n >> l >> r;
        if(n % (l+r) < l) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}