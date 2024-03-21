class Solution {
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>>&dp){
        if(k == s3.size()) {
            if(i == s1.size() && j == s2.size()) return true;
            else return false;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool pick1 = false, pick2 = false;
        if(s1[i] == s3[k]) pick1 = solve(i+1, j, k+1, s1, s2, s3, dp);
        if(s2[j] == s3[k]) pick2 = solve(i, j+1, k+1, s1, s2, s3, dp);
        return dp[i][j][k] = (pick1 || pick2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};