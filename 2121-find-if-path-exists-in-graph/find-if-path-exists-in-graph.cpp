class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[]){
        vis[node] = 1;
        for(auto val : adj[node]){
            if(!vis[val]){
                dfs(val, vis, adj);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n, 0);
        vector<int>adj[n];
        for(auto val : edges){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        dfs(source, vis, adj);
        if(vis[destination]) return true;
        return false;
    }
};