class Solution {
public:
    int solve(int i, int m, int n, vector<string>&strs, vector<vector<vector<int>>>&dp) {
        if(i == strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int a = 0, b = 0;
        for(int j = 0; j<strs[i].size(); j++) {
            if(strs[i][j] == '1') a++;
            else b++;
        }
        int pick = 0;
        if(m >= b && n >= a) pick = 1 + solve(i+1, m-b, n-a, strs, dp);
        int notPick = solve(i+1, m, n, strs, dp);
        return dp[i][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, m, n, strs, dp);
    }
};