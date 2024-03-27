class Solution {
public:
    long long solve(long long i, long long sum, string &s, vector<vector<long long>>&dp) {
        if(i == s.size()) {
            if(sum%25 == 0) return 0;
            return 1e9;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        long long pick = 0 + solve(i+1, (sum*10 + (s[i]-'0'))%25, s, dp);
        long long notPick = 1 + solve(i+1, (sum)%25, s, dp);
        return dp[i][sum] = min(pick, notPick);
    }

    int minimumOperations(string num) {
        vector<vector<long long>>dp(num.size(), vector<long long>(1e4, -1));
        return solve(0ll, 0ll, num, dp);
    }
};