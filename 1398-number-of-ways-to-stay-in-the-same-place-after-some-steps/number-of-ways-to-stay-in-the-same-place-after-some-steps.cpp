class Solution {
public:
    long long mod = 1e9+7;
    long long solve(long long i, long long k, long long n, vector<vector<long long>>&dp) {
        if(k == 0 && i == 0) {
            return 1;
        }
        if(i > k) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 0) return 0;
        long long pick1 = 0, pick2 = 0;
        if(i - 1 >= 0) pick1 = solve(i-1, k-1, n, dp);
        if(i + 1 < n)  pick2 = solve(i+1, k-1, n, dp);
        long long notPick = solve(i, k-1, n, dp);
        return dp[i][k] = (pick1%mod + pick2%mod + notPick%mod)%mod; 
    }

    int numWays(int steps, int arrLen) {
        vector<vector<long long>>dp(steps/2+2, vector<long long>(steps+2, -1));
        return solve(0, steps, arrLen, dp)%mod;
    }
};