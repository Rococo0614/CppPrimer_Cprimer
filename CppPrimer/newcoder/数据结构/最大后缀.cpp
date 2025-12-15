//这个题目值得记住的两个观点：第一，空条件视为真，这里满足 a < j <= a的j不存在，所以按照定义最后一个总是真的最大后缀
//其次，关于异或的用法，如果你已经在结果里面异或了一个数，如果这个数现在要剪掉，就再异或一次这个数就ok，这是异或这个
//算法的结合性
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> stack;  // 存储当前后缀最大值的下标（从栈底到栈顶对应从左到右）
    int xor_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        int idx = i + 1;  // 下标从 1 开始
        // 弹出所有值 <= a[i] 的下标
        while (!stack.empty() && a[stack.back() - 1] <= a[i]) {
            xor_sum ^= stack.back();  // 从异或和中移除
            stack.pop_back();
        }
        // 当前下标入栈
        stack.push_back(idx);
        xor_sum ^= idx;  // 加入异或和
        
        cout << xor_sum << "\n";
    }
    
    return 0;
}