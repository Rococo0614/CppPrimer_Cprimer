#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DirectedGraph{
    private:
    int V;
    vector<set<int>> adj;

    public:
    DirectedGraph(int vertices):V(vertices),adj(vertices+1){}

    void addEdge(int u, int v){
        adj[u].insert(v);
    }

    void PrintGraph(){
        for(int i = 1; i <= V; ++i){
            for(int neighbor : adj[i]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    int T;
    cin >> T;
    vector <DirectedGraph> Graphlist;
    while(T--){
        int n,m;
        cin >> n >> m;
        Graphlist.push_back(DirectedGraph(n));
        while(m--){
            int u,v;
            cin >> u >> v;
            Graphlist.back().addEdge(u,v);
        }
    }
    for(auto& graph : Graphlist){
        graph.PrintGraph();
    }
    return 0;
}