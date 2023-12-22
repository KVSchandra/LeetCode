class Solution {
public:
    int solve(int ind, int k, vector<int>&coins, vector<vector<int>>&dp){
        if(k == 0) return 0;
        if(ind == 0) {
            if(k % coins[ind] == 0) return k/coins[ind];
            else return 1e9;
        }
        if(dp[ind][k] != -1) return dp[ind][k];
        int notPick = 0 + solve(ind-1, k, coins, dp);
        int pick = INT_MAX;
        if(k - coins[ind] >= 0){
            pick = 1 + solve(ind, k-coins[ind], coins, dp);
        }
        return dp[ind][k] = min(notPick,pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};