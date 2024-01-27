class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = solve(i-1, j, n, m, obstacleGrid, dp);
        int right = solve(i, j-1, n, m, obstacleGrid, dp);
        return dp[i][j] = left + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, n, m, obstacleGrid, dp);
    }
};