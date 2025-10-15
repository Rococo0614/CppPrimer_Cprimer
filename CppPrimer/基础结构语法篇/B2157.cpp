#include <iostream>
using namespace std;

int main(){
    int num;
    float sum = 0.0;
    cin >> num;
    for(int i = 0; i < num; i++){
        int temp = 0,flag = 0;
        cin >> temp;
        while(!flag){
            sum += 0.1;
            temp -= 70;
            if(temp > 0){
                flag = 0;
            }
            else{
                if(temp == 0){
                    sum += 0.1;
                }
                flag = 1;
            }

        }
    }
    cout << sum << endl;
    return 0;
}