//对，二分看起来就是小学生一样的思维，但是你得区分二分查找数值区间和二分查找离散答案区分出来，他这个题目不是让你找刚好能覆盖
//那个点对应的半径，而是尝试多次循环计算出来一个差不多的数，你想想实际应用，我可能根本不关心哪些点被盖在里面，我只希望找到
//一个半径，让他差不多能覆盖住我要的S就行，要不然你找点也太麻烦了
#include <bits/stdc++.h>
using namespace std;

struct point{
    double r;
    int v;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,S;
    cin >> n >> S;
    vector<point> p(n);
    double maxR = 0.0;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        p[i].r =sqrt( (long double) x * x + (long double) y * y);
        cin >> p[i].v;
        if(p[i].r > maxR) maxR = p[i].r;
    }

    auto check = [&](double mid) -> bool {
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(p[i].r < mid) {
            sum += p[i].v;
            if(sum >= S) return true;
            }
        }
        return sum >= S;
    };

    if(!check(maxR)){
        cout << -1 << endl;
        return 0;
    }

    double L = 0, R = maxR;
    for(int i = 0; i < 60; i++){
        double mid = (L + R) / 2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << fixed << setprecision(10) << R << endl;
    return 0;


}