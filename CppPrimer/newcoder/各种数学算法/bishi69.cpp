//第一，对于数学算法的思考不太严谨
//第二，你混淆了，在cpp中取模其实是为了与恒等式 a = (a / b) * b + a % b对齐，所以其实cpp里面取的是余数而非模
//但是在新的python版本和matlab就不会存在这个问题，因此在取模的运算里面如果发现有可能是负数，(就+mod) % mod维护为正
#include <bits/stdc++.h>

using namespace std;

const long long P = 100003;
long long fast_pow(long long a, long long b, long long p){
    long long res = 1;
    while(b){
        if(b & 1) res = a * res % p;
        a = a * a % p;
        b >>= 1; 
    }
    return res;
}

int main(){
    long long M,N;
    cin >> M >> N;
    long long res = (fast_pow(M,N,P)- (M * fast_pow(M-1, N-1,P)) % P + P) % P;
    cout << res << endl;
    return 0;
}