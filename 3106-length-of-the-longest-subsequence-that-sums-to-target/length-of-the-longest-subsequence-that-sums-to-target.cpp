class Solution {
public:
    int solve(int i, int k, vector<int>&nums, vector<vector<int>>&dp){
        if(k == 0) return 0;
        if(i == nums.size()) return INT_MIN;
        if(dp[i][k] != -1) return dp[i][k];
        int pick = INT_MIN;
        if(k - nums[i] >= 0) pick = 1 + solve(i+1, k-nums[i], nums, dp);
        int notPick = 0 + solve(i+1, k, nums, dp);
        return dp[i][k] = max(pick, notPick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int ans = solve(0, target, nums, dp);
        if(ans < 0) return -1;
        return ans;
    }
};