class Solution {
public:
    long long solve(long long i, bool flag, long long x, vector<int>&nums, vector<vector<long long>>&dp) {
        if(i == nums.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        long long pick = INT_MIN;
        if(flag == nums[i]%2) pick = nums[i] + solve(i+1, flag, x, nums, dp);
        else pick = nums[i] - x + solve(i+1, !flag, x, nums, dp);
        long long notPick = 0 + solve(i+1, flag, x, nums, dp);
        return dp[i][flag] = max(notPick, pick);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        bool flag = nums[0]%2;
        vector<vector<long long>>dp(nums.size(), vector<long long>(3, -1));
        return solve(0, flag, x, nums, dp);
    }
};