class Solution {
public:
    int solve(int i, int c, vector<int>&satisfaction, vector<vector<int>>&dp){
        if(i == satisfaction.size()) return 0;
        if(dp[i][c] != -1) return dp[i][c];
        int pick = satisfaction[i]*c + solve(i+1, c+1, satisfaction, dp);
        int notPick = 0 + solve(i+1, c, satisfaction, dp);
        return dp[i][c] = max(pick, notPick);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n+10, vector<int>(n+10, -1));
        return solve(0, 1, satisfaction, dp);
    }
};