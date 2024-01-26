class Solution {
public:
    int solve(int i, int j, vector<int>&piles, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick1 = piles[j] + min(solve(i+1, j-1, piles, dp), solve(i, j-2, piles, dp));
        int pick2 = piles[i] + min(solve(i+1, j-1, piles, dp), solve(i+2, j, piles, dp));
        return dp[i][j] = max(pick1, pick2);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int a = solve(0, n-1, piles, dp);
        int b = sum - a;
        // cout<<a<<endl;
        if(b) return true;
        return false;
    }
};