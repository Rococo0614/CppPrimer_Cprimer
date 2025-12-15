//核心思想就是两个分开存储，到时候分开push和pop,很方便
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    deque<char> left_q, right_q;
    int cursor_pos = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            cursor_pos = i;
            break;
        }
        left_q.push_back(s[i]);
    }
    for (int i = cursor_pos + 1; i < n; ++i) {
        right_q.push_back(s[i]);
    }

    for (int i = 0; i < m; ++i) {
        string op;
        cin >> op;
        if (op == "backspace") {
            if (!left_q.empty() && !right_q.empty() && left_q.back() == '(' && right_q.front() == ')') {
                left_q.pop_back();
                right_q.pop_front();
            } else if (!left_q.empty()) {
                left_q.pop_back();
            }
        } else { // delete
            if (!right_q.empty()) {
                right_q.pop_front();
            }
        }
    }

    for (char c : left_q) {
        cout << c;
    }
    cout << 'I';
    for (char c : right_q) {
        cout << c;
    }
    cout << endl;

    return 0;
}
