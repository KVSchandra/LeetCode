class Solution {
public:
    int solve(int i, int sum, int target, vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(i == mat.size()) return abs(sum - target);
        if(dp[i][sum] != -1) return dp[i][sum];
        int mini = INT_MAX;
        for(int j = 0; j < mat[0].size(); j++) {
            mini = min(mini, solve(i+1, sum + mat[i][j], target, mat, dp));
            if(mini == 0) break;
        }
        return dp[i][sum] = mini;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        vector<vector<int>>dp(n, vector<int>(10000, -1));
        return solve(0, sum, target, mat, dp);
    }
};