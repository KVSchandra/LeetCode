class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1000000;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n; j++){
                // if(i == n-1) dp[i][j] = matrix[i][j];
      
                    int down = 10000;
                    int dl = 10000;
                    int dr = 10000;
                    down = matrix[i][j] + dp[i-1][j];
                    if(j > 0) dl = matrix[i][j] + dp[i-1][j-1];
                    if(j < n-1) dr = matrix[i][j] + dp[i-1][j+1];
                    dp[i][j] = min(down, min(dl, dr));
                
            }
        }
        for(int i = 0; i<n; i++){
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};