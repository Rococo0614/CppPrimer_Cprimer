#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    int num;
    float grades;
};

int main(){
    int num,k;
    cin >> num  >> k;
    struct student people[num];
    float grades[num];
        for(int i = 0; i < num; i++){
            cin >> people[i].num >> people[i].grades;
            grades[i] = people[i].grades;
        } 
    stable_sort(grades,grades+num);
    for(int i = 0; i < num;i++){
        if(people[i].grades == grades[k-1]){
            cout << people[i].num << ' ' <<people[i].grades;
            break;
        }
    }
    return 0;

}