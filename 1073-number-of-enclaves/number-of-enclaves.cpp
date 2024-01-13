class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis = grid;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || j == 0|| i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = -1;
                    }
                }
            }
        }
        vector<int>dir = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int dx = x + dir[i];
                    int dy = y + dir[i+1];
                    if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy] == 1){
                        vis[dx][dy] = -1;
                        q.push({dx, dy});
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 1) count++;
            }
        }
        return count;
    }
};