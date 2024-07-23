class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto val : nums) {
            mp[val]++;
        }
        vector<pair<int, int>> v;
        for(auto val : mp) {
            v.push_back({val.second, val.first});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(auto val : v) {
            while(val.first--) {
                ans.push_back(val.second);
            }
        }
        return ans;
    }
};