class Solution {
public: 
    void dfs(int i, int j, int &r1, int &c1, int &r2, int &c2, vector<vector<int>> &vis,vector<vector<int>> &land) {
        vis[i][j] = 1;
        r1 = min(r1, i);
        r2 = max(r2, i);
        c1 = min(c1, j);
        c2 = max(c2, j);
        vector<int>dir = {0, -1, 0, 1, 0};
        for(int k = 0; k<4; k++) {
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dy>=0 && dx<land.size() && dy<land[0].size() && !vis[dx][dy] && land[dx][dy] == 1) {
                dfs(dx, dy, r1, c1, r2, c2, vis, land);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> vis(land.size(), vector<int> (land[0].size(), 0));
        vector<vector<int>> ans;
        for(int i = 0; i<land.size(); i++) {
            for(int j = 0; j<land[0].size(); j++) {
                if(!vis[i][j] && land[i][j] == 1) {
                    int r1 = INT_MAX, r2 = INT_MIN;
                    int c1 = INT_MAX, c2 = INT_MIN;
                    dfs(i, j, r1, c1, r2, c2, vis, land);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        // for(auto val : vis) {
        //     for(auto val1 : val) cout<<val1<<" ";
        //     cout<<endl; 
        // }
        return ans;
    }
};