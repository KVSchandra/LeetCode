class Solution {
public:
    double solve(int poured, int i, int j, vector<vector<double>>&dp) {
        if(i < 0 || i < j || j < 0) return 0.00;
        if(i == 0 && j == 0) return poured;
        if(dp[i][j] != -1) return dp[i][j];
        double left = (solve(poured, i-1, j-1, dp) - 1)/2;
        double right = (solve(poured, i-1, j, dp) - 1)/2;
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        return dp[i][j] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_glass + 1, -1));
        return min(1.00, solve(poured, query_row, query_glass, dp));
    }
};