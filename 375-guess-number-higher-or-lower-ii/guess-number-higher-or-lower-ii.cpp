class Solution {
public:
    int solve(int l, int h, vector<vector<int>> &dp) {
        if(l >= h) return 0;
        if(dp[l][h] != -1) return dp[l][h];
        int mini = INT_MAX;
        for(int i = l; i<=h; i++) {
            mini = min(mini, i + max(solve(l, i-1, dp), solve(i+1, h, dp)));
        }
        return dp[l][h] = mini;
    }

    int getMoneyAmount(int n) {
        int mini = INT_MAX;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
};