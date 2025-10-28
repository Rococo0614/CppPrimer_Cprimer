//本题与41题类似，一个考察大数的除加法，当时的方法是利用整数除法的断尾特性，将相同的除后数放到一起加法，提高效率
//现在我认为方法类似，小于k的算下余数，大于的直接加和。依旧是整除分块

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cout << "plz write n,k" << endl;
    cin >> n >> k;

    long long sum_f = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long v = k / l;
        if (v == 0) {
            // 当 k/l 等于0时，后续所有项的 i * floor(k/i) 也都为0，可以提前结束
            break;
        }
        r = min(n, k / v);
        // 等差数列求和: (首项 + 末项) * 项数 / 2
        long long sum_i = (l + r) * (r - l + 1) / 2;
        sum_f += v * sum_i;
    }

    long long ans = n * k - sum_f;
    cout << ans << endl;

    return 0;
}
