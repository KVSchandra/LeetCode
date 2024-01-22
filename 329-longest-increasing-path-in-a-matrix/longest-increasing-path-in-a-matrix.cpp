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
            int pick = INT_MIN;
            if(dx>=0 && dy>=0 && dx<n && dy<m){
                if(matrix[i][j] < matrix[dx][dy])
                pick = 1 + dfs(dx, dy, matrix, dir, dp);
                // int notPick = 0 + dfs(dx, dy, matrix, dir, dp);
                maxi = max(pick, maxi);
            }
        }
        return dp[i][j] = maxi;
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
        return maxi + 1;
    }
};