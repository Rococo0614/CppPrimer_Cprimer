#include <iostream>
#include <set>

using namespace std;

int main(){
    int num;
    cin >> num;
    multiset<int> s;

    for(int i = 0; i < num; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    for(int x : s){
        cout << x << " ";
    }

    return 0;
    
}