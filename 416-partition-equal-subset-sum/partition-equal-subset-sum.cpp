class Solution {
public:
    bool solve(int ind, int k, vector<int>&nums, vector<vector<int>>&dp){
        if(k == 0) return true;
        if(ind == 0) return (k - nums[ind] == 0);
        if(dp[ind][k] != -1) return dp[ind][k];
        bool notTake = solve(ind-1, k, nums, dp);
        bool take = false;
        if(k - nums[ind] >= 0) take = solve(ind - 1, k-nums[ind], nums, dp);
        return dp[ind][k] = (take | notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        if(sum & 1) return false;
        return solve(n-1, sum/2, nums, dp);
    }
};