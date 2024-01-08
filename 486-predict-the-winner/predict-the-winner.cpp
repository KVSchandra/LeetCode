class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int first_left = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));
        int first_second = nums[j] + min(solve(i, j-2, nums, dp), solve(i+1, j-1, nums, dp));
        return dp[i][j] = max(first_left, first_second);
    }

    bool predictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int player1 = solve(0, n-1, nums, dp);
        if(player1 >= sum - player1) return true;
        return false;
    }
};