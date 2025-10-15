#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class patient{
    public:
    string num;
    int age;
    int signin;
};




int main(){
    int num;
    cin >> num ;
    vector<patient> b2160(num);
    int cnt60 = 0;
    for(int i = 0; i < num; i++){
        cin >> b2160[i].num >> b2160[i].age;
        if(b2160[i].age >= 60){
            cnt60++;
        }
        b2160[i].signin = i;
    }
    sort(b2160.begin(),b2160.end(),[](const patient &a, const patient &b){if(a.age != b.age) return a.age > b.age; else return a.signin < b.signin;});
    sort(b2160.begin()+cnt60,b2160.end(),[](const patient &a, const patient &b){return a.signin < b.signin;});
    for(int i = 0; i < num; i++){
        cout << b2160[i].num << endl;
    }
    return 0;

}