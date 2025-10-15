#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val):data(val),prev(nullptr),next(nullptr){}
};


class LinkedListStack{
    private:
    int stackSize;
    Node* head;
    
    public:
    LinkedListStack():head(nullptr),stackSize(0){}

    ~LinkedListStack(){
        while(!empty())
        pop();
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(empty()){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        stackSize++;
    }

    bool pop(){
        if(empty()){
            cout << "stackoverflow!" << endl;
            return false;
        }
        Node* temp = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete temp;
        stackSize--;
        return true;
    }

    bool top(int &num){
        if(empty()){
            throw runtime_error("Stack is empty!");
            return false;
        }
        num =  head->data;
        return true;
    }

    bool empty(){
        return head == nullptr;
    }

    int size(){
        return stackSize;
    }

};

int main(){
    int num;
    LinkedListStack s;
    cin >> num;
    int num_flag = 0;
    while(num_flag < num){
        int stepnum;
        cin >> stepnum;
        int stepnum_flag = 0;
        while(stepnum_flag < stepnum){
            string step;
            string s1 = "push";
            string s2 = "pop";
            string s3 = "query";
            string s4 = "size";
            cin >> step;
            if(step == s1){
                long long x;
                cin >> x;
                s.push(x);
            }
            else if(step == s2){
                s.pop();
            }
            else if(step == s3){
                int val;
                if(s.top(val))
                cout << val << endl;
            }
            else if(step == s4){
                cout << s.size() << endl;
            }
            else{
                cerr << "STR" << endl;
                return -1;
            }
            stepnum_flag++;
        }
        num_flag++;
    }
    return 0;
}