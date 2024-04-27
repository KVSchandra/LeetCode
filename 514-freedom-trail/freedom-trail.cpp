class Solution {
public:
    int solve(int i, int j, string &key, string &ring, vector<vector<int>>&dp) {
        if(j == key.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = 0; k<ring.size(); k++) {
            if(ring[k] == key[j]) {
                mini = min((long long)mini, 1 + min((long long)abs(k-i), (long long)ring.size()-abs(k-i)) + solve(k, j+1, key, ring, dp));
            }
        }
        return dp[i][j] = mini;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.size(), vector<int>(key.size()+1, -1));
        return solve(0, 0, key, ring, dp);
    }
};