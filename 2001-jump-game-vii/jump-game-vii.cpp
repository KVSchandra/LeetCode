class Solution {
public:
    bool solve(int i, int minJump, int maxJump, string &s, vector<int>&dp) {
        if(i == s.size()-1) return true;
        if(s[i] == '1') return dp[i] = false;
        if(minJump + i >= s.size()) return false;
        if(dp[i] != -1) return dp[i];
        int a = min((int)i+maxJump, (int)s.size()-1);
        for(int j = i+minJump; j <= a; j++) {
            if(s[j] == '0' && solve(j, minJump, maxJump, s, dp)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

    bool canReach(string s, int minJump, int maxJump) {
        vector<int>dp(s.size(), -1);
        if(s.back() == '1') return false;
        int count = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '1') {count++; if(count >= maxJump) return false;}
            else count = 0;
        }
        return solve(0, minJump, maxJump, s, dp);
    }
};