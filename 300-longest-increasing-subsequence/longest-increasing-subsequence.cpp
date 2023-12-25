class Solution {
public:
    int solve(int ind, int prevInd, int &n, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        int take = INT_MIN;
        if(prevInd == -1 || nums[prevInd] < nums[ind]){
            take = 1 + solve(ind + 1, ind, n, nums, dp);
        }
        int notTake = 0 + solve(ind + 1, prevInd, n, nums, dp);
        return dp[ind][prevInd + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, n, nums, dp);
    }
};