class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto val : nums) mp[val]++;
        vector<pair<int, int>>v;
        for(auto val : mp){
            v.push_back({val.second, val.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        vector<int>ans;
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};