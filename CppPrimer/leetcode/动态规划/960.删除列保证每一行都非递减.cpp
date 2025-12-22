//看上去考的还是维护是否删除和单调增，但是实际上这个问题的体积最大100*100，可以考虑动态规划
//实际上多维偏序最长列没有低于m2的方法，真正用在工程中也对有限对二维做SVD之类的
//所以该方法是目前能公开的最优解
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m,1);
        int ans = 1;

        for(int j = 0; j < m; j++){
            for(int k = 0; k < j; k++){
                bool ok = true;
                for(int i = 0; i < n; i++){
                    if(strs[i][k] > strs[i][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){//这两列对于n行都ok，那就可以把他加进来
                dp[j] = max(dp[j], dp[k] + 1);
                }
            }
            ans = max(ans, dp[j]);
        }
        return m - ans; 
    }
    
};