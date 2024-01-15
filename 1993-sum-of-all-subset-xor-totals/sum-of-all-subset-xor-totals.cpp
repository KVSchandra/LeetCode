class Solution {
public:
    int solve(int i, int x, int n, vector<int>&nums, vector<vector<int>>&dp){
        if(i == n) return x;
        if(dp[i][x] != -1) return dp[i][x];
        int pick = solve(i+1, x^nums[i], n, nums, dp);
        int notPick = solve(i+1, x, n, nums, dp);
        return dp[i][x] = pick + notPick;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        // int sum = 0;
        vector<vector<int>>dp(n, vector<int>(100, -1));
        return solve(0, x, n, nums, dp);
    }
};