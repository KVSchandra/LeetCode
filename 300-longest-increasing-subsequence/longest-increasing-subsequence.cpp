class Solution {
public:
    int solve(int i, int prevInd, int &n, vector<int>&nums, vector<vector<int>>&dp) {
        if(i == n) return 0;
        if(dp[i][prevInd+1] != -1) return dp[i][prevInd+1];
        int take = 0;
        if(prevInd == -1 || nums[i] > nums[prevInd]) {
            take = 1 + solve(i+1, i, n, nums, dp);
        }
        int notTake = 0 + solve(i+1, prevInd, n, nums, dp);
        return dp[i][prevInd + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, n, nums, dp);
    }
};