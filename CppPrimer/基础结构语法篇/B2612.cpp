#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;
    cin >> num;
    vector <int> arr(num+1,0);
    for(int i = 1; i <= num; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= num; i++){
        arr[i] += arr[i-1];
    }

    int nsum;
    cin >> nsum;
    vector <int> tsum(nsum,0);
    for(int i = 0; i < nsum;i++){
        int L,R;
        cin >> L >> R;
        tsum[i] = arr[R] - arr[L-1];
    }
    for(int i = 0; i < nsum; i++){
        cout << tsum[i] << endl;
    }
    return 0;
}