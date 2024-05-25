class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int prev, vector<int>&nums, vector<vector<int>>&dp) {
        if(i == nums.size()) return prev == 2;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int pick = 0;
        if((prev == -1 || prev == 0) && (nums[i] == 0)) pick = solve(i+1, 0, nums, dp);
        if((prev == 0  || prev == 1) && (nums[i] == 1)) pick = solve(i+1, 1, nums, dp);
        if((prev == 1  || prev == 2) && (nums[i] == 2)) pick = solve(i+1, 2, nums, dp);
        int notPick = solve(i+1, prev, nums, dp);
        return dp[i][prev+1] = ((pick)%mod + (notPick)%mod)%mod;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(4, -1));
        return solve(0, -1, nums, dp)%mod;
    }
};