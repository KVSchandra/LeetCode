const int mod = 1e9+7;
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int s, int k, vector<vector<int>>& types) {
        if(s == k) return 1;
        if(i >= types.size() || s > k) return 0;
        if(dp[i][s] != -1) return dp[i][s];
        int pick = 0;
        for(int j = 1; j <= types[i][0]; j++) {
            if(s + j*(types[i][1]) <= k) {
                pick = (pick + solve(i+1, s+(j*(types[i][1])), k, types)) % mod;
            }
            else break;
        }
        int notPick = solve(i+1, s, k, types);
        return dp[i][s] = (pick + notPick) % mod;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        dp.resize(types.size()+1, vector<int>(target+10, -1));
        return solve(0, 0, target, types);
    }
};