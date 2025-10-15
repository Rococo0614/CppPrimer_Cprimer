#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct volunteer {
    int num;
    int grade;
};

bool cmp(const volunteer &a, const volunteer &b) {
    if (a.grade != b.grade)
        return a.grade > b.grade;
    else
        return a.num < b.num;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    int cnt = round(num2 * 1.5); // 四舍五入

    vector<volunteer> vol(num1);
    for (int i = 0; i < num1; i++) {
        cin >> vol[i].num >> vol[i].grade;
    }

    sort(vol.begin(), vol.end(), cmp);

    // 如果越界，限制 cnt
    if (cnt > num1) cnt = num1;

    // 处理分数相同的边界情况（并列全部入围）
    while (cnt < num1 && vol[cnt - 1].grade == vol[cnt].grade) {
        cnt++;
    }

    cout << vol[cnt - 1].grade << " " << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        cout << vol[i].num << " " << vol[i].grade << endl;
    }

    return 0;
}