class Solution {
public:
    int solve(int i, int prev, vector<vector<int>>&grid, vector<vector<int>>&freq, vector<vector<int>>&dp) {
        if(i == grid[0].size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int mini = INT_MAX;
        for(int j = 0; j<freq[i].size(); j++) {
            if(j != prev)
            mini = min((long long)mini, (long long)grid.size()-freq[i][j] + solve(i+1, j, grid, freq, dp));
        }
        return dp[i][prev+1] = mini;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>>freq;
        for(int j = 0; j<grid[0].size(); j++) {
            vector<int>vis(10, 0);
            for(int i = 0; i<grid.size(); i++) {
                vis[grid[i][j]]++;
            }
            freq.push_back(vis);
        }
        vector<vector<int>>dp(grid[0].size(), vector<int>(11, -1));
        return solve(0, -1, grid, freq, dp);
    }
};