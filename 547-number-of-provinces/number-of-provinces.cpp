class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[]) {
        vis[node] = 1;
        for(auto val : adj[node]) {
            if(!vis[val]){
                dfs(val, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //Converting matrix to list
        int V = isConnected.size();
        vector<int>adj[V];
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int>vis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};