class Solution {
public:
    int solve(int i, int prevInd, int n, vector<int>&nums, vector<vector<int>>&dp){
        if(i == n) return 0;
        int pick = INT_MIN;
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];
        if(prevInd == -1 || nums[prevInd] < nums[i]){
            pick = 1 + solve(i+1, i, n, nums, dp);
        }
        int notPick = 0 + solve(i+1, prevInd, n, nums, dp);
        return dp[i][prevInd + 1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, n, nums, dp);
    }
};