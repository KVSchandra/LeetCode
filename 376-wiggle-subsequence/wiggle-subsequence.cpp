class Solution {
public:
    int solve(int i, int prevInd, int diff, int n, vector<int>&nums, vector<vector<vector<int>>>&dp){
        if(i == n) return 0;
        if(dp[i][prevInd + 1][diff] != -1) return dp[i][prevInd + 1][diff];
        int pick = INT_MIN;
        if(prevInd == -1 || (diff == 0 && nums[prevInd] < nums[i]) || (diff == 1 && nums[prevInd] > nums[i])){
            pick = 1 + solve(i+1, i, !diff, n, nums, dp);
        }
        int notPick = 0 + solve(i+1, prevInd, diff, n, nums, dp);
        return dp[i][prevInd + 1][diff] = max(pick, notPick);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n+2, vector<int>(3, -1)));
        return max(solve(0, -1, 1, n, nums, dp), solve(0, -1, 0, n, nums, dp));
    }
};