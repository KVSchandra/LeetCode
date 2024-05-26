class Solution {
public:
    long long mod = 1e9+7;
    long long solve(long long i, long long j, long long n, vector<vector<vector<long long>>>&dp) {
        if(i >= 3 || j >= 2) return 0;
        if(dp[n][i][j] != -1) return dp[n][i][j];
        if(n == 0) return 1;
        long long pick1 = solve(i+1, j, n-1, dp);
        long long pick2 = solve(0, j+1, n-1, dp);
        long long notPick = solve(0, j, n-1, dp);
        return dp[n][i][j] = (pick1%mod + pick2%mod + notPick%mod)%mod;
    }

    int checkRecord(int n) {
        vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(4, vector<long long>(3, -1)));
        return solve(0, 0, n, dp);
    }
};