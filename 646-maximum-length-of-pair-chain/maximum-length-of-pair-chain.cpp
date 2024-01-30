class Solution {
public:
    int solve(int i, int prevInd, vector<vector<int>>&pairs, vector<vector<int>>&dp){
        if(i == pairs.size()) return 0;
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];
        int pick = INT_MIN;
        if(prevInd == -1 || pairs[prevInd][1] < pairs[i][0]) pick = 1 + solve(i+1, i, pairs, dp);
        int notPick = 0 + solve(i+1, prevInd, pairs, dp);
        return dp[i][prevInd + 1] = max(pick, notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs, dp);
    }
};