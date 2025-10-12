#include <iostream>
using namespace std;

int jiecheng(int num){
    int sum = 1;
    for(int i = 1; i <= num; i++){
        sum *= i;
    }
    return sum;
}

int main(){
    int num;
    cin >> num ;
    int sum = 0;
    for(int i = 1; i <= num; i++){
        sum += jiecheng(i);
    }
    cout << sum;
    return 0;

}