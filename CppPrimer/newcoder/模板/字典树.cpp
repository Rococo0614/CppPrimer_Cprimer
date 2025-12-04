//真正的coo精妙程度从这里才开始，慢慢体会
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool isEnd;
    int cnt;

    TrieNode():isEnd(false),cnt(0){}; 
};

class Tries{
    private:
    TrieNode* root;

    public:
    Tries():root(new TrieNode()) {};

    void insert(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            cur->cnt++;
        }
        cur->isEnd = true;
    }

    int calprefix(const string& word){
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c) == cur->children.end()){
                return 0;
            }
            cur = cur->children[c];
        }
        return cur->cnt;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin >> n >> q;
    Tries tries;
    while(n--){
        string s; cin >> s;
        tries.insert(s);
    }
    while(q--){
        string t; cin >> t;
        cout << tries.calprefix(t) <<endl;
    }
    return 0;
}