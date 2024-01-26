class Solution {
public:
    double solve(int i, int j, int k, int n, vector<pair<int, int>>&dir, vector<vector<vector<double>>>&dp){
        if(i < 0 || j < 0 || i>=n || j>=n) return 0.0;
        if(k == 0) return 1.0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        double a = 0;
        for(auto val : dir){
            a += (solve(i + val.first, j + val.second, k-1, n, dir, dp)/8);
        }
        return dp[i][j][k] = a;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>>dir = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        double a = solve(row, column, k, n, dir, dp);
        // double ans = a/(8.0);
        return a;
    }
};