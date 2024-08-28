class Solution {
public:
    vector<int>dir = {0, -1, 0, 1, 0};
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || grid2[i][j] == 0) {
            return;
        }
        grid2[i][j] = 0;
        for(int k = 0; k < 4; k++) {
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            dfs(dx, dy, grid1, grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 0) {
                    dfs(i, j, grid1, grid2);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1) {
                    count++;
                    dfs(i, j, grid1, grid2);
                }
            }
        }
        return count;
    }
};