#include <iostream>
#include <string.h>
using namespace std;

class student{
    public:
    char name[20];
    int grades;
};


void BubbleSort(struct student arr[],int num){
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1;j++){
            if(arr[j].grades < arr[j + 1].grades){
                struct student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;  
            }
        }
    }

}

void namesort(struct student arr[],int num){
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(arr[j].grades == arr[j+1].grades){
                if(strcmp(arr[j].name, arr[j+1].name) > 0){
                    struct student temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

    }
}

int main(){
    int num;
    cin >> num;
    class student b2159[num];
    for (int i = 0; i < num; i++){
        cin >> b2159[i].name >> b2159[i].grades;
    }
    BubbleSort(b2159,num);
    namesort(b2159,num);
    for(int i = 0; i < num; i++){
        cout << b2159[i].name << " " << b2159[i].grades << endl;
    }
    return 0;

}