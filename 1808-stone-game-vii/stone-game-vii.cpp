class Solution {
public:
    int solve(int i, int j, vector<int>&stones, int sum, vector<vector<int>>&dp) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick1 = sum-stones[i] - solve(i+1, j, stones, sum-stones[i], dp);
        int pick2 = sum-stones[j] - solve(i, j-1, stones, sum-stones[j], dp);
        return dp[i][j] = max(pick1, pick2);
    }                                                       

    int stoneGameVII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>>dp(stones.size(), vector<int>(stones.size(), -1));
        int a = solve(0, stones.size()-1, stones, sum, dp);
        return a;
    }
};