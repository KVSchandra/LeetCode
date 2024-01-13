class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis = image;
        vector<int>v = {0, 1, 0, -1, 0};
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int prev = vis[sr][sc];
        vis[sr][sc] = color;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int dx = x + v[i];
                    int dy = y + v[i+1];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < m && vis[dx][dy] == prev && image[dx][dy] != color) {
                        vis[dx][dy] = color;
                        q.push({dx, dy});
                    }
                }
            }
        }
        return vis;
    }
};