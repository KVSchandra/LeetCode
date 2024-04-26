class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i >= grid.size() || j >= grid.size() || i < 0 || j < 0) return 100000;
        if(i == grid.size()-1) return grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int pick1 = 1000000;
        for(int k = 0; k<grid.size(); k++) {
            if(k!=j) {
                pick1 = min(pick1, grid[i][j] + solve(i+1, k, grid, dp));
            }
        }
        return dp[i][j] = pick1;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX;
        vector<vector<int>>dp(grid.size(), vector<int>(grid.size(), INT_MAX));
        for(int j = 0; j<grid.size(); j++) {
            mini = min(mini, solve(0, j, grid, dp));
        }
        return mini;
    }
};