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

    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>vis(n+1, 0);
        vector<int>adj[n+1];
        for(auto val : roads){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        dfs(1, vis, adj);
        int mini = INT_MAX;
        for(auto val : roads){
            if(vis[val[0]]){
                mini = min(mini, val[2]);
            }
        }
        return mini;
    }
};