#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int idx = 0;
    int w = 0, l = 0;
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == 'W') w++;
        if(s[i] == 'L') l++;
        if(((w >= 11 || l >= 11) && abs(w-l) >= 2) || i == s.size()-1){
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
        
    }
    return 0;
}