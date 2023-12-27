class Solution {
public:
    int solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp) {
        if(i == -1) {
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target+2000] != -1) return dp[i][target+2000];
        int pos = solve(i-1, target - nums[i], nums, dp);
        int neg = solve(i-1, target + nums[i], nums, dp);
        return dp[i][target+2000] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target + 100000, -1));
        return solve(n-1, target, nums, dp);
    }
};