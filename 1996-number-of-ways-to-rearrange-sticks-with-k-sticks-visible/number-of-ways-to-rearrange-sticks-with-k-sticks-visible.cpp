class Solution {
public:
    long long mod = 1e9+7;
    long long solve(long long n, long long k, vector<vector<long long>>&dp) {
        if(k == n) return 1;
        if(k == 0 || k > n) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        long long ans = (solve(n-1, k-1, dp))%mod + (solve(n-1, k, dp)*(n-1)%mod)%mod;
        return dp[n][k] = ans%mod;
    }

    int rearrangeSticks(int n, int k) {
        vector<vector<long long>>dp(n+1, vector<long long>(k+1, -1));
        return solve(n, k, dp)%mod;
    }
};