class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int prev2, int prev1, int n, vector<vector<vector<vector<int>>>>&dp) {
        if(n == 0) return 1;
        if(dp[i][n][prev2+1][prev1+1] != -1) return dp[i][n][prev2+1][prev1+1];
        int pick = 0;
        for(int j = 1; j<=6; j++) {
            if(prev2 == -1) {
                pick = (pick + solve(j, j, prev1, n-1, dp))%mod;
            }
            else if(prev1 == -1) {
                if(__gcd(i, j) == 1 && j != prev2) {
                    pick = (pick + solve(j, prev2, j, n-1, dp))%mod;
                }
            }
            else {
                if(__gcd(i, j) == 1 && j != prev2 && j != prev1) {
                    pick = (pick + solve(j, prev1, j, n-1, dp))%mod;
                }
            }
        }
        return dp[i][n][prev2+1][prev1+1] = pick%mod;
    }

    int distinctSequences(int n) {
        vector<vector<vector<vector<int>>>>dp(9, vector<vector<vector<int>>>(n+1, vector<vector<int>>(8, vector<int>(8, -1))));
        return solve(0, -1, -1, n, dp);
    }
};