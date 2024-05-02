class Solution {
public:
    // int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
    //     if(i == text1.size() || j == text2.size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int match = INT_MIN;
    //     if(text1[i] == text2[j]) match = 1 + solve(i+1, j+1, text1, text2, dp);
    //     int notMatch = 0 + max(solve(i+1, j, text1, text2, dp), solve(i, j+1, text1, text2, dp));
    //     return dp[i][j] = max(match, notMatch);
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }           
        }
        return dp[n][m];
        // vector<int> curr(m+1, 0), prev(m+1, 0);
        // for(int i = n-1; i>=0; i--) {
        //     for(int j = m-1; j>=0; j--) {
        //         if(text1[i] == text1[j]) curr[j] = 1 + prev[j+1];
        //         else curr[j] = max(prev[j], curr[j+1]);
        //     }
        //     prev = curr;
        // }
        // return curr[0];
    }
};