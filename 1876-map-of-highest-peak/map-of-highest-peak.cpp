class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>ans;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        vector<int>dir = {0, -1, 0, 1, 0};
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(isWater[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++) {
                    int dx = i + dir[k];
                    int dy = j + dir[k+1];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && vis[dx][dy] == -1) {
                        vis[dx][dy] = vis[i][j] + 1;
                        q.push({dx, dy});
                    }
                }
            }
        }
        return vis;
    }
};