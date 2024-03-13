int solve(int i, vector<int>&nums, unordered_map<int, int>&mp, vector<int>&dp){
    if(i == nums.size()-1) return mp[nums[i]];
    else if(i >= nums.size()) return 0;
    int pick = 0;
    if(dp[i] != -1) return dp[i];
    if(i+1 < nums.size()) {
        if(nums[i+1] - nums[i] == 1) pick = mp[nums[i]] + solve(i+2, nums, mp, dp);
        else if(nums[i+1] - nums[i] != 1) pick = mp[nums[i]] + solve(i+1, nums, mp, dp);
    }
    int notPick = 0 + solve(i+1, nums, mp, dp);
    return dp[i] = max(pick, notPick);
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto &val : nums){
            if(mp.find(val) != mp.end()){
                mp[val] += val;
            }
            else mp[val] = val;
        }
        set<int>st;
        for(auto val : nums) st.insert(val);
        nums.clear();
        for(auto val : st) nums.push_back(val);
        vector<int>dp(nums.size(), -1);
        return solve(0, nums, mp, dp);
    }
};