class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, unordered_map<int, unordered_map<int, int>>&dp) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i].find(j) != dp[i].end()) return dp[i][j];
        int pick = 0;
        if(s1[i] == s2[j]) pick = int(s1[i]) + solve(i+1, j+1, s1, s2, dp);
        int notPick = max(solve(i+1, j, s1, s2, dp), solve(i, j+1, s1, s2, dp));
        return dp[i][j] = max(pick, notPick);
    } 

    int minimumDeleteSum(string s1, string s2) {
        unordered_map<int, unordered_map<int, int>>dp;
        int a = solve(0, 0,  s1, s2, dp);
        long long sum1 = 0, sum2 = 0;
        for(auto val : s1) {
            sum1 += int(val);
        }
        sum1 -= a;
        for(auto val : s2) {
            sum2 += int(val);
        }
        sum2 -= a;
        return sum1 + sum2;
    }
};