class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<int>dir = {0, 1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int size = q.size();
            count++;
            while(size--) {
                auto val = q.front();
                q.pop();
                for(int i = 0; i<4; i++) {
                    int dx = val.first + dir[i];
                    int dy = val.second + dir[i+1];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy] == 0) {
                        vis[dx][dy] = 1;
                        q.push({dx, dy});
                    }
                }
            }
        }
        if(count-1 == 0) return -1;
        return count-1;
    }
};