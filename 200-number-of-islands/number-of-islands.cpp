class Solution {
public:
    void bfs(int x, int y, vector<vector<int>>&vis, vector<vector<char>>&grid) {
        vis[x][y] = 1;
        queue<pair<int,int>>q;
        q.push({x, y});
        vector<int> v = {0 , 1, 0, -1, 0};
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int dx = q.front().first;
            int dy = q.front().second;
            q.pop();
            for(int i = 0 ; i<4; i++){
                int r = dx + v[i], c = dy + v[i+1];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == '1' && !vis[r][c]){
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};