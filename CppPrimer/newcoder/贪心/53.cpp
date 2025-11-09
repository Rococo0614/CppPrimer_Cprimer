#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 高精度数结构体
struct BigInt {
    string digits;

    BigInt(long long n = 0) : digits(to_string(n)) {}
    BigInt(string s) : digits(s) {
        if (digits.empty()) digits = "0";
    }
};

// 比较两个高精度数
bool operator<(const BigInt& a, const BigInt& b) {
    if (a.digits.length() != b.digits.length()) {
        return a.digits.length() < b.digits.length();
    }
    return a.digits < b.digits;
}

// 高精度数乘以int
BigInt operator*(const BigInt& a, int b) {
    if (a.digits == "0" || b == 0) return BigInt(0);
    string res = "";
    int carry = 0;
    for (int i = a.digits.length() - 1; i >= 0; --i) {
        carry += (a.digits[i] - '0') * b;
        res += to_string(carry % 10);
        carry /= 10;
    }
    if (carry) res += to_string(carry);
    reverse(res.begin(), res.end());
    return BigInt(res);
}

// 高精度数除以int
BigInt operator/(const BigInt& a, int b) {
    string res = "";
    long long rem = 0;
    for (char digit : a.digits) {
        rem = rem * 10 + (digit - '0');
        res += to_string(rem / b);
        rem %= b;
    }
    size_t first_digit = res.find_first_not_of('0');
    if (string::npos != first_digit) {
        return BigInt(res.substr(first_digit));
    }
    return BigInt(0);
}

struct Minister {
    int id;
    long long a, b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long king_a, king_b;
    cin >> king_a >> king_b;

    vector<Minister> ministers(n);
    for (int i = 0; i < n; ++i) {
        ministers[i].id = i;
        cin >> ministers[i].a >> ministers[i].b;
    }

    sort(ministers.begin(), ministers.end(), [](const Minister& m1, const Minister& m2) {
        return m1.a * m1.b < m2.a * m2.b;
    });

    BigInt product(king_a);
    BigInt max_reward(0);

    for (int i = 0; i < n; ++i) {
        BigInt current_reward = product / ministers[i].b;
        if (max_reward < current_reward) {
            max_reward = current_reward;
        }
        product = product * ministers[i].a;
    }

    cout << max_reward.digits << '\n';

    return 0;
}
