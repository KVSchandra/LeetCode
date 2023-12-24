class Solution {
public:
    int solve(int i, int buy, vector<int>&prices, int n, vector<vector<int>>&dp){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1){
            int buys = -prices[i] + solve(i+1, 0, prices, n, dp);
            int notBuys = 0 + solve(i+1, 1, prices, n, dp);
            return dp[i][buy] = max(buys, notBuys);
        }
        else {
            int sell = prices[i] + solve(i+1, 1, prices, n, dp);
            int notSell = 0 + solve(i+1, 0, prices, n, dp);
            return dp[i][buy] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, 1, prices, n, dp);
    }
};