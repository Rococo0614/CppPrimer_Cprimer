#include <iostream>
#include <memory>

using namespace std;

class Queue{
    private:
    struct Node{
        int data;
        unique_ptr<Node> next;
        Node(int val): data(val), next(nullptr) {}
    };

    unique_ptr<Node> front;
    Node* rear;
    int size;

    public:
    Queue() : front(nullptr), rear(nullptr), size(0){}
    ~Queue() = default;

    bool isEmpty() {
        return front == nullptr;
    }

    void addQueue(int val){
        auto newNode = make_unique<Node>(val);
        if(rear == nullptr){
            front = move(newNode);
            rear = front.get();
            size++;
        }
        else{
            rear->next = move(newNode);
            rear = rear->next.get();
            size++;
        }
        return;
    }

    void deQueue(){
        if(isEmpty()){
            throw runtime_error("ERR_CANNOT_POP");
        }
        int value = front->data;
        front = move(front->next);
        if(front == nullptr){
            rear = nullptr;
        }
        size--;
        return;
    }

    int peek(){
        if(isEmpty()){
            throw runtime_error("ERR_CANNOT_QUERY");
        }
        return front->data;
    }

    int Getsize(){
        return size;
    }
};


int main(){
    int stcnt;
    cin >> stcnt;
    Queue que;
    while(stcnt--){
        int st;
        cin >> st;
       try{
         switch(st){
            case 1:{
                int num;
                cin >> num;
                que.addQueue(num);
                break;
            }
            case 2:{
                que.deQueue();
                break;
            }
            case 3:{
                cout << que.peek() << endl;
                break;
            }
            case 4:{
                cout << que.Getsize() <<endl;
                break;
            }
        }
    } 
    catch (const runtime_error& e){
        cout << e.what() << endl;
    }
    }
    return 0;
}