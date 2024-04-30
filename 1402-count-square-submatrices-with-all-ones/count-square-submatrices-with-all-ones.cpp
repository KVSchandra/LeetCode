class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>> &dp) {
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = 1 + solve(i, j+1, matrix, dp);
        int down = 1 + solve(i+1, j, matrix, dp);
        int diag = 1 + solve(i+1, j+1, matrix, dp);
        return dp[i][j] = min(right, min(down, diag));
    }

    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i<matrix.size(); i++) {
            for(int j = 0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 1) {
                    ans += solve(i, j, matrix, dp);
                }
            }
        }
        return ans;
    }
};