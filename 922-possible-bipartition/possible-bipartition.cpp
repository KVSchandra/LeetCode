class Solution {
public:
    bool bfs(int i, vector<int>&vis, vector<int>adj[]){
        queue<int>q;
        q.push(i);
        vis[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]){
                if(vis[adjNode] == -1){
                    vis[adjNode] = !vis[node];
                    q.push(adjNode);
                }
                else if(vis[adjNode] == vis[node]) return false;
            }
        }
        return true;
    }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto val : dislikes){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        vector<int>vis(n+1, -1);
        for(int i = 1; i<=n; i++){
            if(vis[i] == -1){
                if(bfs(i, vis, adj) == 0) return false;
            }
        }
        return true;
    }
};