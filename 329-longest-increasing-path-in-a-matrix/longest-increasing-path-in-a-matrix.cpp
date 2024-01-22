class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&matrix, vector<int>&dir, vector<vector<int>>&dp){
        int maxi = 0;
        if(dp[i][j] != -1) return dp[i][j];
        int n = matrix.size();
        int m = matrix[0].size();
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && matrix[i][j] < matrix[dx][dy]){
                maxi = max(maxi, dfs(dx, dy, matrix, dir, dp));
            }
        }
        return dp[i][j] = 1 + maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        int maxi = INT_MIN;
        int mx = 0;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                maxi = max(maxi, dfs(i, j, matrix, dir, dp));
            }
        }
        return maxi;
    }
};