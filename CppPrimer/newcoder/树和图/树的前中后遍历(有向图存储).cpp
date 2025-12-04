#include <bits/stdc++.h>
using namespace std;

void preorder(int root,map<int,pair<int,int>>& children){
    if(root == 0) return;
    cout << root << " ";
    preorder(children[root].first,children);
    preorder(children[root].second,children);
}

void midorder(int root, map<int,pair<int,int>>& children){
    if(root == 0) return;
    midorder(children[root].first,children);
    cout << root << " ";
    midorder(children[root].second,children);
}

void backorder(int root, map<int,pair<int,int>>& children){
    if(root == 0) return;
    backorder(children[root].first,children);
    backorder(children[root].second,children);
    cout << root << " ";
}




int main(){
    int n; cin >> n;
    if(n == 1){
        cout << "1\n1\n1\n";
        return 0;
    }
    vector<pair<int,int>> edges;
    n -= 1;
    while(n--){
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    map<int,pair<int,int>> children; //初始化默认pair里头两个0
    for(auto& [a,b] : edges){ //省一次拷贝的值
        if(children[a].first == 0){
            children[a].first = b; 
        }
        else if(children[a].second == 0){
            if(b < children[a].first){
                children[a].second = children[a].first;
                children[a].first = b;
            }
            else{
                children[a].second = b;
            }
        }
    }

    for(auto& [a,pi] : children){
        if(pi.second == 0 && pi.first != 0){
            if(pi.first < a){
                pi.second = pi.first;
                pi.first = 0;
            }
        }
    }

    set<int> childnote;
    for(auto& [parent,pi] : children){
        if(pi.first) childnote.insert(pi.first);
        if(pi.second) childnote.insert(pi.second);
    }

    int root = -1;
    for(auto& [parent,pi] :children){
        if(childnote.count(parent) == 0){
            root = parent;
            break;
        }
    }

    preorder(root,children); cout << endl;
    midorder(root,children); cout << endl;
    backorder(root,children);
}