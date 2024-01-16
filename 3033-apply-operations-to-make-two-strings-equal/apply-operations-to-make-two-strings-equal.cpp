class Solution {
public:
    int solve(int i, int j, int x, vector<int>&v, vector<vector<int>>&dp){
        if(i == v.size()) return 0;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = v[i+1] - v[i] + solve(i+2, j, x, v, dp);
        int b = v[j] - v[j-1] + solve(i, j-2, x, v, dp);
        int c = x + solve(i+1, j-1, x, v, dp);
        return dp[i][j] = min(c, min(a, b));
    }

    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        vector<int>v;
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]) v.push_back(i);
        }
        if(v.size() & 1) return -1;
        int j = v.size()-1;
        vector<vector<int>>dp(n, vector<int>(j+1, -1));
        return solve(0, j, x, v, dp);
    }
};