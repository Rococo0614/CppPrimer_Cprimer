//核心目标：求最长回文子串
//方法：首先把字符串处理，保证所有回文串长度都为奇数
//维护数组p，代表i下标处的回文半径（包含i），思考一下就能得到补充后的回文半径是子回文串长度+1
//对每个点统计半径长度，线性方法是：如果一个字符所在的位置在我之前统计的很长的回文串子字符串内，那么他一定关于这个
//很长的子字符串对称，根据这个性质可以快速得到一个基数，然后尝试基于这个基数进行扩展
#include <bits/stdc++.h>
using namespace std;

string prefix(const string& s) {
    if (s.empty()) return "^$";
    string t;
    t.reserve(s.size() * 2 + 3);
    t.push_back('^');
    t.push_back('#');
    for (char ch : s) {
        t.push_back(ch);
        t.push_back('#');
    }
    t.push_back('$');
    return t;
}

int themaxrstr(const string& t) {
    vector<int> p(t.size(), 0);
    int center = 0, right = 0;
    for (int i = 1; i < t.size() - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);
        else
            p[i] = 1;

        while (t[i + p[i]] == t[i - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    int maxlen = 0;
    for(int i = 1; i < t.size() - 1; i++){
        if(p[i] > maxlen) maxlen = p[i];
    }
    return maxlen - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int t = themaxrstr(prefix(s));
    cout << t << endl;
    return 0;
}
