0.最开始的内容，32位是2.1x10的9次方，所以能存下10的9次方的数字；64位是9.22x10的18次方，所以能存下10的18次方的数字

0.1各种运算符号中，按位操作稍微记得几个基础的，与&,或|,非(按位置取反是~)异或 ^ 就是二进制后按位置，相同的输出0, 不同的输出1
应当注意到，机器存储所有的数都是按照二进制存储的，所以如果题目要求的是位操作运算的话，直接使用就好，如果你希望看到输出也是二进制，要么for循环+string
要么include <bitset> bitset<你需要的位数> bits(你想要转换的数字)

0.2.关于运算符号的优先问题
大部分情况下不会出错，此处先简单列一些坑
各种逻辑门的运算优先度比较低，取地址，引用解引用优先级很高
对于按位置与或异或的优先级低于乘除和加减
三元运算符的优先级可以说是非常低的一类，尤其是比输出<<的优先级要低，因此输出的时候记得加括号 cout << (cond ? A : B)这样

0.3如果你想提高计算效率，可以采取以下两行指令:
ios::sync_with_stdio(false);//“不要再让 C++ 的 cin/cout 与 C 的 scanf/printf 同步缓冲区。”,通常输入输出性能提高2～5倍
cin.tie(nullptr);//默认情况下,每次执行 cin >> ... 之前，都会自动刷新 cout 的缓冲区,这样就避免了频繁的缓冲刷新，速度一般提升20%~30%。

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

同时应当注意，vector除非在push_back的情况下才能有值，如果你在输入的时候对于vector的一个值没有对应的push_back，那他的.size() = 0,因此不会有任何输出；

4.对于string的用法
4.1字符串的初始化
我们应当知道，在cpp中。字符串的初始化是默认为0,即 string s; s.empty()则等于1;
4.2字符串的添加和删去
当我们引入了标准库之后，都会都一种结构进行完整的基础功能构建
如果我们想添加字符，我们应该使用 s += "abc" 或者 s.push_pack("abc")或者s.append("abc")
4.3针对输入的是一句话，想统计单次，该如何做到？
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

5.关于哈希表
哈希表一般是用来快速查找某一元素或一个元素及其对应关系的方法；前一个是Key,后一个是Value
1.查找元素,或者统计元素数量,使用无序表unordered_map<template,template> out//此处的out对应的是第二个template
如果只想去掉重复元素或者快速判断有没有,可以使用unordered_set<template> out,此处只存储Key
注意，哈希表，不论有序还是无顺序，本质都是高级数据结构（数组+链表），现成哈希表可以使用insert()和erase()操作


2.若想有序输出，需要使用map/set,底层是红黑树，此时可以查询范围，并看到最大最小值和最小最大值等操作。


5.关于运算符号的优先问题
大部分情况下不会出错，此处先简单列一些坑
各种逻辑门的运算优先度比较低，取地址，引用解引用优先级很高
三元运算符的优先级可以说是非常低的一类，尤其是比输出<<的优先级要低，因此输出的时候记得加括号 cout << (cond ? A : B)这样


6.