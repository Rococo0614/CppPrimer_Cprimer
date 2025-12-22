//从左到右的思想是想出来了，但是对于相等的边界处理不到位导致转不过弯来
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int cnt = 0;
        
        for (int col = 0; col < m; col++) {
            bool deleteThisCol = false;
            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    deleteThisCol = true;
                    break;
                }
            }
            if (deleteThisCol) {
                cnt++;
            } else {
                for (int row = 0; row < n - 1; row++) {
                    if (strs[row][col] < strs[row + 1][col]) {
                        sorted[row] = true;
                    }
                }
            }
        }
        return cnt;
    }
};