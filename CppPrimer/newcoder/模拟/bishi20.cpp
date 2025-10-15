#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isLeap(int years){
    if((years % 4 == 0 && years % 100 != 0) || years % 400 == 0){
        return true;
    }
    return false;
};

bool isValid(string s){
    if(stoi(s.substr(4,2)) > 12) return false;
    static int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeap(stoi(s.substr(0,4)))){
        days[1] = 29;
    }
    if(stoi(s.substr(6,2)) > days[stoi(s.substr(4,2)) - 1]) return false;
    return true;
}

int main(){
    string a1,a2;
    cin >> a1 >> a2;
    
    int cnt = 0;
    for(int i = 1000; i <= 9999; i++){
        string s1 = to_string(i);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string slib = s1 + s2;
        if(slib >= a1 && slib <= a2 && isValid(slib)){
            cnt++;
        }
    }
    cout << cnt << endl; 
}