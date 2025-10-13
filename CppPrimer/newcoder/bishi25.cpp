//曼哈顿距离,任意两个函数之间的差的绝对值的和的最大值可以拆成一类函数对于一个变量的值的多种变化进行统计

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;
    vector<long long> A;

    long long max1 = LLONG_MIN, min1 = LLONG_MAX;
    long long max2 = LLONG_MIN, min2 = LLONG_MAX;
    long long max3 = LLONG_MIN, min3 = LLONG_MAX;
    long long max4 = LLONG_MIN, min4 = LLONG_MAX;
    for(int i = 1; i <= num; i++){
        long long temp;
        cin >> temp;
        long long x = 1LL*i*i;
        long long y = 1LL*temp*temp;

        max1 = max(max1, x + y);
        min1 = min(min1, x + y);
        max2 = max(max2, x - y);
        min2 = min(min2, x - y);
        max3 = max(max3, -x + y);
        min3 = min(min3, -x + y);
        max4 = max(max4, -x - y);
        min4 = min(min4, -x - y);
    }

    long long ans = max({max1-min1,max2-min2,max3-min3,max4-min4});

    cout << ans << endl;

    return 0;
}