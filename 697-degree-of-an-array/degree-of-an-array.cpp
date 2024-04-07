class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>mp;
        int maxi = INT_MIN;
        for(auto val : nums) {
            mp[val]++;
        }
        for(auto val : mp) {
            maxi = max(maxi, val.second);
        }
        int i = 0, j = 0;
        int ans = INT_MAX;
        mp.clear();
        while(j < nums.size()) {
            mp[nums[j]]++;
            while(mp[nums[j]] == maxi) {
                ans = min(ans, j-i+1);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};