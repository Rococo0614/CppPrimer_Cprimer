#include <iostream>
#include <string>
using namespace std;

class ArrayStack{
    private:
    static const int MAX_SIZE = 1e6 + 10;
    long long arr[MAX_SIZE];
    int topIndex;

    public:
    ArrayStack() : topIndex(-1) {};

    ~ArrayStack(){
        delete[] arr;
    }

    void push(int x){
        if(topIndex == MAX_SIZE - 1){
            cout << "full!" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    void pop(){
        if(empty()){
            cout << "Empty" << endl;
            return;
        }
        topIndex--;
    }

    bool top(int& outValue){
        if(empty()){
            cout << "Anguei!" <<endl;
            return false;
        }
        outValue =  arr[topIndex];
        return true;
    }

    bool empty(){
        return topIndex == -1;
    }

    int size(){
        return topIndex + 1;
    }

};


int main(){
    int num;
    ArrayStack s;
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