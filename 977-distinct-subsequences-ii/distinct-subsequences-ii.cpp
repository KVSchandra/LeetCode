class Solution {
public:
    int mod = 1e9+7;

    int solve(int i, string &s, vector<int>&dp) {
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        vector<int>vis(26, 0);
        int count = 0;
        for(int j = i; j<s.size(); j++) {
            if(vis[s[j]-'a'] == 0) {
                vis[s[j]-'a'] = 1;
                count += (1 + solve(j+1, s, dp))%mod;
                count %= mod;
            }
        }
        return dp[i] = count;
    }

    int distinctSubseqII(string s) {
        vector<int>dp(s.size()+1, -1);
        return solve(0, s, dp);
    }
};