#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string line;
    getline(cin,line);

    stringstream ss(line);
    string word;
    map<string,int> freq;
    while(ss >> word){
        freq[word]++;
    }
    vector<pair<string, int>> vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(),[](const pair<string,int>& a, const pair<string,int>& b){
        if(a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    });

    for (auto &p: vec){{
        if(p.second >= 3)
            cout << p.first << endl;
        }
    }

    return 0;
}