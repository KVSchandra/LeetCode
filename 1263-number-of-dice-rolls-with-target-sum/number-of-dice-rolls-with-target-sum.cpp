class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int target, int k, int n, vector<vector<int>>&dp) {
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        long long count = 0;
        for(int j = 1; j<=k; j++) {
            if(target >= j) count += solve(i+1, target-j, k, n, dp)%mod;
        }
        return dp[i][target] = count%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return solve(0, target, k, n, dp)%mod;
    }
};