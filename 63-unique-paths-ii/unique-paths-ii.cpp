class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int left = 0;
                    int up = 0;
                    if(i-1 >= 0) left = dp[i-1][j];
                    if(j-1 >= 0) up = dp[i][j-1];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[n-1][m-1];
    }
};