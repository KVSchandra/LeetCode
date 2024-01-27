class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i = n-1; i>=0; i--){
            for(int j = triangle[i].size()-1; j>=0; j--){
                if(i == n-1) dp[i][j] = triangle[i][j];
                // else if(j == n) dp[i][j] = INT_MAX;
                else dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};