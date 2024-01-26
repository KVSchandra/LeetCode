class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int j, int maxMove, int &m, int &n, vector<vector<vector<int>>>&dp){
        if(i < 0 || j < 0 || i>=m || j>=n) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        vector<int>dir = {0, 1, 0, -1, 0};
        int a = 0;
        for(int k = 0; k<4; k++){
            a = (a + solve(i + dir[k], j + dir[k+1], maxMove-1, m, n, dp)) % mod;
        }
        return dp[i][j][maxMove] = (a % mod);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, maxMove, m, n, dp);
    }
};