class Solution {
public:
    bool bfs(int i, vector<int>&vis, vector<vector<int>>&graph){
        vis[i] = 0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto val : graph[node]){
                if(vis[val] == -1){
                    vis[val] = !vis[node];
                    q.push(val);
                }
                else if(vis[val] == vis[node]) return false;       
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        for(int i = 0; i<n; i++){
            if(vis[i] == -1){
                if(bfs(i, vis, graph) == 0) return false;
            }
        }
        return true;
    }
};