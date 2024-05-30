class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
        if(j == grid[0].size()-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick1 = 0, pick2 = 0, pick3 = 0;
        if(grid[i][j+1] > grid[i][j]) pick1 = 1 + solve(i, j+1, grid, dp);
        if(i+1 < grid.size() && grid[i+1][j+1] > grid[i][j]) pick2 = 1 + solve(i+1, j+1, grid, dp);
        if(i-1 >= 0 && grid[i-1][j+1] > grid[i][j]) pick3 = 1 + solve(i-1, j+1, grid, dp);
        return dp[i][j] = max({pick1, pick2, pick3});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i = 0; i < grid.size(); i++) {
            maxi = max(maxi, solve(i, 0, grid, dp));
        }
        return maxi;
    }
};