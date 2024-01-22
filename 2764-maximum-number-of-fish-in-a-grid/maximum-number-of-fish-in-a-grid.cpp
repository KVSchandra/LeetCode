class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, int &sum){
        vis[i][j] = 1;
        sum += grid[i][j];
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy] && vis[dx][dy] == -1){
                // sum += grid[dx][dy];
                dfs(dx, dy, grid, vis, sum );
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>>vis(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == -1 && grid[i][j]){
                    int sum = 0;
                    dfs(i, j, grid, vis, sum);
                    maxi = max(maxi, sum);
                }   
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]) return maxi;
            }
        }
        return maxi;
    }
};