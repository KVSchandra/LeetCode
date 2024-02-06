class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy] && !vis[dx][dy]){
                maxi = max(grid[dx][dy] + dfs(dx, dy, vis, grid), maxi);  
            }
        }
        vis[i][j] = 0;
        return maxi;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    maxi = max(maxi, grid[i][j] + dfs(i, j, vis, grid));
                }
            }
        }
        return maxi;
    }
};