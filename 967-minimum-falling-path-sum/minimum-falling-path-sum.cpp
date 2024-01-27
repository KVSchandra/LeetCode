class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(j >= n || j < 0) return 1000000;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != 101) return dp[i][j];
        int down = matrix[i][j] + solve(i+1, j, n, matrix, dp);
        int diag_left = matrix[i][j] + solve(i+1, j-1, n, matrix, dp);
        int diag_right = matrix[i][j] + solve(i+1, j+1, n, matrix, dp);
        return dp[i][j] = min(down, min(diag_left, diag_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, 101));
        for(int j = 0; j<n; j++){
            mini = min(mini, solve(0, j, n, matrix, dp));
        }
        return mini;
    }
};