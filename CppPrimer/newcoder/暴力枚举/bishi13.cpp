#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;
    cin >> num;
    while (num--) {
        string a;
        cin >> a;
        int a_dissum = 0, count2 = 0, count3 = 0, diff = 0;
        for (int i = 0; i < a.size(); i++) {
            int c = a[i] - '0';
            a_dissum += c;
            if (c == 2) count2++;
            if (c == 3) count3++;
        }
        diff = a_dissum % 9;
        if (diff == 0) {
            cout << "YES" << endl;
            continue;
        } else {
            bool ok = false;
            for (int i = 0; i <= count2 && !ok; i++) {
                for (int j = 0; j <= count3; j++) {
                    if ((diff + i * 2 + j * 6) % 9 == 0) {
                        cout << "YES" << endl;
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) {
                cout << "NO" << endl;
            }

        }
    }
    return 0;
}