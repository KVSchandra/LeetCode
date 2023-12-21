class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1000;
        if(dp[i][j] != -1) return dp[i][j];
        int sum_left = grid[i][j] + solve(i-1,j,grid,dp);
        int sum_up = grid[i][j] + solve(i,j-1,grid,dp);
        return dp[i][j] = min(sum_left,sum_up); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};