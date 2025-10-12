#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    while (num--) {
        int op_num;
        int odd_num = 0, even_num = 0, odd_sum = 0, even_sum = 0;
        cin >> op_num;
        if (op_num >= 3) {
            vector<int> a(op_num, 0);
            for (int i = 0; i < op_num; i++) {
                cin >> a[i];
                if (i % 2 == 0) {
                    even_num++;
                    even_sum += a[i];
                } else {
                    odd_sum += a[i];
                }
            }
            int sum = accumulate(a.begin(), a.end(), 0);
            if (sum % op_num != 0) {
                cout << "NO" << endl;
                continue;
            } else {
                odd_num = op_num - even_num;
                if((odd_sum % odd_num == 0) && (even_sum % even_num == 0) && (even_sum / even_num == odd_sum / odd_num)){
                    cout << "YES" << endl;
                    continue;
                }
                else{
                    cout << "NO" << endl;
                    continue;
                }

            }

        }
        else{
            switch(op_num){
                case 1:{
                    cout << "YES" << endl;
                    break;
                }
                case 2:{
                    int a1, a2;
                    cin >> a1 >> a2;
                    if(a1 == a2){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                    break;
                }
            }
        }

    }
    return 0;
}