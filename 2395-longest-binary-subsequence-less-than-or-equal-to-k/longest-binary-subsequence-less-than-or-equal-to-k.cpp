class Solution {
public:
    int solve(int i, int k, int n, string s, vector<int>&dp){
        if(i == n) return 0;
        // if(k == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = 0;
        if(k - ((s[i]-'0')*pow(2,i)) >= 0) pick = 1 + solve(i + 1, k-((s[i]-'0')*pow(2,i)), n, s, dp);
        int notPick = 0 + solve(i+1, k, n, s, dp);
        return dp[i] =  max(pick, notPick);
    }
    
    int longestSubsequence(string s, int k) {
        int n = s.size();
        reverse(s.begin(), s.end());
        vector<int>dp(n+1, -1);
        return solve(0, k, n, s, dp);
    }
};