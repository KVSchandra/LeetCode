class Solution {
public:
    int solve(int i, int buy, int k, int &n, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(i == n) return 0;
        if(k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        if(buy) {
            int buys = -prices[i] + solve(i+1, 0, k, n, prices, dp);
            int notBuys = 0 + solve(i+1, 1, k, n, prices, dp);
            return dp[i][buy][k] = max(buys, notBuys);
        }
        else {
            int sell = prices[i] + solve(i+1, 1, k-1, n, prices, dp);
            int notSell = 0 + solve(i+1, 0, k, n, prices, dp);
            return dp[i][buy][k] = max(sell, notSell);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, n, prices, dp);
    }
};