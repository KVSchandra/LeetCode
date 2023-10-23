class Solution {
public:
    int solve(int n,vector<int>&nums,vector<int>&dp){
        dp[0] = nums[0];
            for (int i = 1; i <= n; i++)
            {
                int pick = nums[i];
                if (i > 1) pick = pick + dp[i - 2];
                int notPick = 0 + dp[i - 1];
                dp[i] = max(pick, notPick);
            }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};