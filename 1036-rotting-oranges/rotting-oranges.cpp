class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>v = {0, 1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int dx = r + v[i];
                    int dy = c + v[i+1];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy] == 1){
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0) return -1;
        if(ans == -1) return 0;
        return ans;
    }
};