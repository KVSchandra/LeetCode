class Solution {
public:
    int solve(int i, int k, vector<int>&v, vector<vector<int>>&dp){
        if(i == v.size()) return 1000;
        if(k == 0) return 1;
        if(dp[i][k] != -1) return dp[i][k];
        int pick = INT_MAX;
        if(k - v[i] >= 0) {
            pick = 1 + solve(i, k-v[i], v, dp);
            int notPick = solve(i+1, k, v, dp);
            if(pick == INT_MAX) pick = 0;
            return dp[i][k] = min(pick, notPick);
        }
        return dp[i][k] = solve(i+1, k, v, dp);
        
    }
    int numSquares(int n) {
        vector<int>v;
        int i = 1;
        while(i*i <= n){
            v.push_back(i*i);
            i++;
        }
        vector<vector<int>>dp(v.size(), vector<int>(n+1, -1));
        return solve(0, n, v, dp)-1;
    }
};