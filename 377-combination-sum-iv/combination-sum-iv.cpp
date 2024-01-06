class Solution {
public:
    int solve(int i, int k, vector<int>&nums, vector<vector<int>>&dp) {
        if(i == nums.size()) return 0;
        if(k == 0) return 1;
        if(dp[i][k] != -1) return dp[i][k];
        int pick = 0;
        if(k - nums[i] >= 0){
            pick = solve(0, k-nums[i], nums, dp);
        }
        int notPick = solve(i+1, k, nums, dp);
        return dp[i][k] = pick + notPick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return solve(0, target, nums, dp);
    }
};