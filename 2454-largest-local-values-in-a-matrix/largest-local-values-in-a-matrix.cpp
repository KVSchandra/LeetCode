class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid.size()-2, vector<int>(grid.size()-2));
        for(int i = 1; i<grid.size()-1; i++) {
            for(int j = 1; j<grid.size()-1; j++) {
                int maxi = INT_MIN;
                maxi = max({maxi, grid[i][j], grid[i-1][j], grid[i][j-1], grid[i-1][j-1], grid[i+1][j], grid[i][j+1], grid[i+1][j+1], grid[i+1][j-1], grid[i-1][j+1]});
                ans[i-1][j-1] = maxi;
            }
        }
        return ans;
    }
};