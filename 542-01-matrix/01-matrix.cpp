class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
        vector<int>v = {0, 1, 0, -1, 0};
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int Dx = x + v[i];
                    int Dy = y + v[i+1];
                    if(Dx>=0 && Dy>=0 && Dx<n && Dy<m && ans[Dx][Dy] == -1){
                        q.push({Dx, Dy});
                        ans[Dx][Dy] = ans[x][y] + 1;
                    }
                }
            }
        }
        return ans;
    }
};