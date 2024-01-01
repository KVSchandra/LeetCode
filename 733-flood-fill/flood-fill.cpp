class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        if(ini == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans(n, vector<int>(m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m; j++){
                ans[i][j] = image[i][j];
            }
        }
        ans[sr][sc] = color;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        vector<int>v = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int dx = x + v[i];
                int dy = y + v[i+1];
                if(dx>=0 && dy>=0 && dx<n && dy<m && ans[dx][dy] == ini && image[dx][dy]!=color){
                    q.push({dx, dy});
                    ans[dx][dy] = color;
                }
            }
        }
        return ans;
    }
};