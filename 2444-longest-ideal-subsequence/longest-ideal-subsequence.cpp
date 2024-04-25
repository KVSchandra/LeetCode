class Solution {
public:
    int solve(int i, char prev, string &s, int k, vector<vector<int>> &dp) {
        if(i >= s.size()) return 0;
        if(dp[i][abs(prev-'a')+1] != -1) return dp[i][abs(prev-'a')+1];
        int pick = INT_MIN;
        if(prev == '1' || abs(prev - s[i]) <= k) {
            pick = 1 + solve(i+1, s[i], s, k, dp);
        }
        int notPick = 0 + solve(i+1, prev, s, k, dp);
        return dp[i][abs(prev-'a')+1] = max(pick, notPick);
    }

    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size()+2, vector<int>(125, -1));
        return solve(0, '1', s, k, dp);
    }
};