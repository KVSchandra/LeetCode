class Solution {
public:
    int solve(int ind, int k, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0) return (k % coins[ind] == 0);
        if(dp[ind][k] != -1) return dp[ind][k];
        int notPick = 0 + solve(ind-1, k, coins, dp);
        int pick = 0;
        if(k - coins[ind] >= 0) pick = solve(ind, k - coins[ind], coins, dp);
        return dp[ind][k] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1, amount, coins, dp);
    }
};