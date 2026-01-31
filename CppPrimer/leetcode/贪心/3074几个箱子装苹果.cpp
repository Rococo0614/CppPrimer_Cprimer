//很简单一个题，主要是处理边界条件
//如果相等减掉还得看正好合适的情况下数字对不对
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),[](const int& a,const int& b){
            return a > b;
        });
        int sum = 0,cnt = 0;
        for(int i = 0; i < apple.size(); i++){
            sum += apple[i];
        }
        for(int i = 0; i < capacity.size(); i++){
            cnt++;
            if(sum > capacity[i]){
                sum -= capacity[i];
            }
            else{
                return cnt;
            }
        }
        return cnt;
        
    }
};