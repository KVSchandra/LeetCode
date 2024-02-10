class Solution {
public:
    bool solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool pick = false;
        if(s[i] == s[j]) pick =  solve(i+1, j-1, s, dp);
        bool notPick = false;
        return dp[i][j] = pick | notPick;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(solve(i, j, s, dp)) count++;
            }
        }
        return count;
    }
};