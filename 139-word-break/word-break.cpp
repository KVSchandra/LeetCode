class Solution {
public:
    bool solve(int i,string &s, unordered_map<string, int>&mp, vector<int>&dp) {
        if(i == s.size()) {
            return true;
        }
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.size(); j++) {
            string a = s.substr(i, j-i+1);
            if(mp.find(a) != mp.end()) {
                if(solve(j+1, s, mp, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>mp;
        for(auto val : wordDict) mp[val]++;
        vector<int>dp(s.size(), -1);
        return solve(0, s, mp, dp);
    }
};