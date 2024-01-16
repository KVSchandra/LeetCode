class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&grid, vector<int>&dir){
        vis[i][j] = 1;
        // grid[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k<4; k++){
                int dx = x + dir[k];
                int dy = y + dir[k+1];
                if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy] == 0){
                    q.push({dx, dy});
                    // grid[dx][dy] = 1;
                    vis[dx][dy] = 1; 
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dir = {0, 1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && (grid[i][j] == 0 && !vis[i][j])){
                    bfs(i, j, vis, grid, dir);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bfs(i, j, vis, grid, dir);
                    count++;
                }
            }
        }
        return count;
    }
};