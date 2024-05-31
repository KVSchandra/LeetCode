class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto val : nums) mp[val]++;
        priority_queue<pair<int, int>>pq;
        for(auto val : mp) pq.push({val.second, val.first});
        vector<int>ans;
        while(!pq.empty()) {
            auto a = pq.top();
            if(a.first == 0) break;
            ans.push_back(a.second);
            pq.pop();
            if(pq.empty()) break;
            auto b = pq.top();
            pq.pop();
            ans.push_back(b.second);
            if(b.first-1) pq.push({b.first-1, b.second});
            if(a.first-1) pq.push({a.first-1, a.second});
        }
        return ans;
    }
};