class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto val : nums) {
            mp[val]++;
        }
        int maxi = INT_MIN;
        for(auto val : mp) {
            if(maxi < val.first) {
                int a = -1*val.first;
                if(mp.find(a) != mp.end()) {
                    maxi = val.first;
                }
            }
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};