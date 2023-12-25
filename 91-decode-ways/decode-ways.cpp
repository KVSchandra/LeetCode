class Solution {
public:
    int solve(int i, int &n, string &s, vector<int>&dp){
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int count = 0;
        if(s[i] != '0') count += solve(i+1, n, s, dp);
        if(s[i] == '1'|| (s[i] == '2' && s[i+1] <= '6')) count += solve(i+2, n, s, dp);
        return dp[i] = count;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return solve(0, n, s, dp);
    }
};