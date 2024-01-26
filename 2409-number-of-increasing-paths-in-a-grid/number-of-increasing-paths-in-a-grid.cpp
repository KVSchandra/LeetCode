class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy] > grid[i][j]){
                ans += (solve(dx, dy, grid, dp)%mod);
            }
        } 
        return dp[i][j] = (ans + 1) % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = (ans + solve(i, j, grid, dp)) % mod;
            }
        }
        return ans % mod;
    }
};