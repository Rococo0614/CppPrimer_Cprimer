#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s,t;
    cin >> s;
    int s_len = s.size();
    cin >> t;
    int t_len = t.size();
    vector<int> times_tochange(t_len-s_len+1,0);
    for(int i = 0; i < t_len-s_len+1; i++){
        for(int j = i; j < i+s_len; j++){
            times_tochange[i] += min(abs(t[j]-s[j-i]),26-abs(t[j] - s[j-i]));
        }
    }
    cout << *min_element(times_tochange.begin(),times_tochange.end()) << endl;
    return 0;
}