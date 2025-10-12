1.针对 n++, ++n, n+1的联系与区别:


2.排序，针对一个结构体中的两种或多种进行排序(如分数从小到大，再按姓名首字母排序)
使用sort + 自定义比较函数

#include <algorithm>
#include <string>
#include <vector>

struct people{
    int id;
    string name;
    int grade;
}

bool cmp(const people &a, const people &b){
    if(a.grade != b.grade){
        return a.grade > b.grade;
    }
    else{
        return a.name < b.name;
    }
}

int main(){
    cin >> num;
    vector<people> pp;
    for(int i = 0; i < num; i++){
        cin >> pp[i].id >> pp[i].name >> pp[i].grade;
    }
    sort(pp.begin(),pp.end(),cmp);
}

或者使用lambda表达式，将函数定义直接写在排序里面

sort(pp.begin(), pp.end(),[](const people &a, const people &b) {
    if(a.grade != b.grade)
    return a.grade > b.grade;
    else
    return a.name < b.name;
});


3.关于vector的用法
一维：
如果已知容量大小num，直接使用vector<template> temp(num),之后直接通过下标访问即可
如果容量大小未知，需要动态添加: vector<template> temp,之后template tmp;temp.push_back(tmp);

二维:
已知容量大小，n行m列,使用vector<vector<template>> temp(n, vector<template>(m))
此时的初始化默认为0，如果想初始化为其他值的话，选取 vector<vector<template>> temp(n,vector<template>(m,'想要的字符'))即可
之后通过下标访问即可
如果容量大小未知,需要在循环中添加 vector<vector<template>> temp; 

4.对于string的用法
首先，string直接统计的是字符串，且遇到输入字符串中间带空格的时候停止，
那么不仅要问，如果我有一个字符串，中间有很多空格，直到\n才停止的时候，我该怎么办？
使用getline即可，例如
#include <string>
#include <sstream>

sring line;
getline(cin, line);

stringstream ss(line); //保存到ss输入流里面，重载之后就可以使用string了，类似与矩阵分别输入数字和直接输入矩阵，然后进行操作
string word;
while(ss >> word){
    进行你需要的操作;
}



