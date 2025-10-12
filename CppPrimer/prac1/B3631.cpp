#include <iostream>
#include <unordered_map>
using namespace std;


struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int val):value(val), prev(nullptr),next(nullptr){}
};


class LinkedListTable{
    private:
    unordered_map<int,Node*> nodeMap;
    Node* head;

    public:
    LinkedListTable(){
        head = new Node(-1);
        head->next = new Node(1);
        head->next->prev = head;
        nodeMap[1] = head->next;
    }

    ~LinkedListTable(){

    }

    void insertAfter(int x,int y){
        Node* xNode = nodeMap[x];
        Node* newnode = new Node(y);

        newnode->next = xNode->next;
        newnode->prev = xNode;
        if(xNode->next){
            xNode->next->prev = newnode;
        }
        xNode->next = newnode;

        nodeMap[y] = newnode;
    }

    int queryAfter(int x){
        Node* xNode = nodeMap[x];
        if(!xNode->next) return 0;
        return xNode->next->value;
    }

    void deleteAfter(int x){
        Node* xNode = nodeMap[x];
        if(!xNode->next) return;

        Node* todelete = xNode->next;
        xNode->next = todelete->next;
        if(todelete->next){
            todelete ->next->prev = xNode;
        }
        nodeMap.erase(todelete->value);
        delete todelete;
    }

};


int main(){
    LinkedListTable table;
    int opCount;
    cin >> opCount;

    while(opCount--){
        int op,x,y;
        cin >> op;

        if(op == 1){
            cin >> x >> y;
            table.insertAfter(x,y);
        }
        else if(op == 2){
            cin >> x;
            cout << table.queryAfter(x) << endl;
        }
        else if(op == 3){
            cin >> x;
            table.deleteAfter(x);
        }


    }
    return 0;
}