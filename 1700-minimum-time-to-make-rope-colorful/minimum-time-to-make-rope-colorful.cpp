class Solution {
public:
    int solve(int i, int prev, string &colors, vector<int>&neededTime, vector<vector<int>>&dp) {
        if(i == neededTime.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int take = neededTime[i] + solve(i+1, prev, colors, neededTime, dp);
        int notTake = INT_MAX;
        if(prev != (colors[i] - 'a')) notTake = 0 + solve(i+1, colors[i] - 'a', colors, neededTime, dp);
        return dp[i][prev] = min(take, notTake);
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>>dp(n, vector<int>(27, -1));
        return solve(0,  26, colors, neededTime, dp);
    }
};