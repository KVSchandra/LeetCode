class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 0}});
        vis[0][0] = 1;
        vector<int>dir = {0, 1, 0, -1, 0};
        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int wt = pq.top().first;
            pq.pop();
            if(i == n-1 && j == m-1) return wt;
            for(int k = 0; k<4; k++){
                int dx = i + dir[k];
                int dy = j + dir[k+1];
                if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy]){
                    pq.push({wt + grid[dx][dy], {dx, dy}});
                    vis[dx][dy] = 1;
                }
            }
        }
        return 0;
    }
};