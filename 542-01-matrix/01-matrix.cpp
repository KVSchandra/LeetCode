class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 0;
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
                    if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy] == -1){
                        vis[dx][dy] = vis[x][y] + 1;
                        q.push({dx, dy});
                    }
                }
            }
        }
        return vis;
    }
};