class Solution {
public:
    int solve(int i, int &n, vector<int>cost, vector<int>&dp){
        if(i == 0 || i == 1) return cost[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int one = cost[i] + solve(i-1, n, cost, dp);
        int two = cost[i] + solve(i-2, n, cost, dp);
        return dp[i] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        int a = solve(n-1, n, cost, dp);
        int b = solve(n-2, n, cost, dp);
        return min(a, b);
    }
};