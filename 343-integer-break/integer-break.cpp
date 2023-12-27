class Solution {
public:
    int solve(int i, int sum, vector<int>&v, vector<vector<int>>&dp){
        if(i == v.size()) return 0;
        if(sum == 0) return 1;
        if(dp[i][sum] != -1) return dp[i][sum];
        int pick = INT_MIN;
        if(sum - v[i] >= 0) pick = v[i] * solve(i, sum-v[i], v, dp);
        int notPick = solve(i+1, sum, v, dp);
        return dp[i][sum] = max(pick, notPick);
    }

    int integerBreak(int n) {
        vector<int>v;
        for(int i = 1;i<n;i++) v.push_back(i);
        int sum = n;
        vector<vector<int>>dp(n, vector<int>(59, -1));
        return solve(0, sum, v, dp);
    }
};