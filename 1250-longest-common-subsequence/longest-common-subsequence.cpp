class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>>&dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1 + solve(i-1, j-1, text1, text2, dp);
        return dp[i][j] = 0 + max(solve(i-1, j, text1, text2, dp), solve(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1, text1, text2, dp);
    }
};