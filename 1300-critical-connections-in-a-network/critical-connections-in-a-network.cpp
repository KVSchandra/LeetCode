class Solution {
public:
    void dfs(int node, int parent, vector<int>&tin, vector<int>&low, int time, vector<int>&vis, vector<int>adj[], vector<vector<int>>&ans){
        vis[node] = 1;
        tin[node] = time;
        low[node] = time;
        time++;
        for(auto val : adj[node]){
            if(val == parent) continue;
            if(!vis[val]){
                dfs(val, node, tin, low, time, vis, adj, ans);
                low[node] = min(low[node], low[val]);
                if(tin[node] < low[val]){
                    ans.push_back({node, val});
                }
            }
            else {
                low[node] = min(low[node], tin[val]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>tin(n);
        vector<int>low(n);
        vector<int>vis(n, 0);
        int time = 0;
        vector<vector<int>>ans;
        vector<int>adj[n];
        for(auto val : connections){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        dfs(0, -1, tin, low, time, vis, adj, ans);
        return ans;
    }
};