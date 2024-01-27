class Solution {
public:
    int solve(int i, int n, vector<int>&nums, vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + solve(i+2, n, nums, dp);
        int notPick = 0 + solve(i+1, n, nums, dp);
        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        if(n == 1) return nums[0];
        return max(solve(0, n-1, nums, dp1), solve(1, n, nums, dp2));
    }
};