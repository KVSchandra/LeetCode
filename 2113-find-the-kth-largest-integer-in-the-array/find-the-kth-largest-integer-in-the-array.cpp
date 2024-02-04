class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int, string>>pq;
        for(auto val : nums){
            pq.push({val.size(), val});
        }
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top().second;
    }
};