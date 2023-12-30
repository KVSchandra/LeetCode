class Solution {
public:
    bool solve(int i, int k, int n, vector<int>&nums, vector<vector<int>>&dp) {
        if(i == n-1) return (k == nums[i]);
        if(k == 0) return true;
        if(dp[i][k] != -1) return dp[i][k];
        int take = false;
        if(k - nums[i] >= 0) take = solve(i+1, k-nums[i], n, nums, dp);
        int notTake = solve(i+1, k, n, nums, dp);
        return dp[i][k] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(0, sum/2, n, nums, dp);
    }
};