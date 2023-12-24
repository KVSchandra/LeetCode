class Solution {
public:
    int solve(int i, int buy, int transaction, int &n, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(transaction == 0) return 0;
        if(i == n) return 0;
        if(dp[i][buy][transaction] != -1) return dp[i][buy][transaction];
        if(buy == 1){
            int buys = -prices[i] + solve(i+1, 0, transaction, n, prices, dp);
            int notBuys = 0 + solve(i+1, 1, transaction, n, prices, dp);
            return dp[i][buy][transaction] = max(buys, notBuys);
        }
        else{
            int sell = prices[i] + solve(i+1, 1, transaction-1, n, prices, dp);
            int notSell = 0 + solve(i+1, 0, transaction, n, prices, dp);
            return dp[i][buy][transaction] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, n, prices, dp);
    }
};