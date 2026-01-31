//看到这玩意第一个想法是dp，不过由于只需要找俩，用小顶堆加排序，然后基于排序的性质去找所有能满足开始时间大于结束时间的最高价值的
//然后进行结合
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int max_value = 0,max_sec = 0;
        for(auto& e : events){
            int start = e[0], end = e[1], value = e[2];

            while(!pq.empty() && pq.top().first < start){
                auto sec_chose = pq.top();
                max_sec = max(max_sec,sec_chose.second);
                pq.pop();
            }
            max_value = max(max_value,value + max_sec);
            pq.push({end,value});
        }
        return max_value;
    }
};