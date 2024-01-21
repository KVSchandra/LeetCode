class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        if(n == 1){
            if(grid[0][0] == 0) return 1;
            return -1;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int dx = -1; dx<=1; dx++){
                for(int dy = -1; dy<=1; dy++){
                    int x = row + dx;
                    int y = col + dy;
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 0 && dist[x][y] > dist[row][col]+1){
                        dist[x][y] = dist[row][col] + 1;
                        pq.push({dist[x][y], {x, y}});
                        if(x == n-1 && y == n-1){
                            return dist[x][y] + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};