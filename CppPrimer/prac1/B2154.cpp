#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int cnt = 0;
    for(int i = 1; i <= num; i++){
        int temp = i;
        while(temp > 0){
            if(temp % 10 == 1){
                cnt++;
                temp /= 10;
            }
            else{
                temp /= 10;
            }
        }

    }
    cout << cnt;
    return 0;
}