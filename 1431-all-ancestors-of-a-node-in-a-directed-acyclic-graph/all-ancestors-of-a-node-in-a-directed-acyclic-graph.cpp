class Solution {
public:
    void dfs(int i, vector<int>& temp, vector<int> adj[], vector<bool>& vis) {
        for(auto val : adj[i]) {
            if(!vis[val]) {
                vis[val] = true;
                temp.push_back(val);
                dfs(val, temp, adj, vis);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<int> adj[n];
        for(auto& val : edges) {
            adj[val[1]].push_back(val[0]);
        }
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            vector<bool> vis(n, false);
            dfs(i, temp, adj, vis);
            sort(temp.begin(), temp.end());
            ans[i] = temp;
        }
        return ans;
    }
};
