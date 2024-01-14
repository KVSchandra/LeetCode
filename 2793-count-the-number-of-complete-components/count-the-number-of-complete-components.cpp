class Solution {
public:
    void bfs(int i, vector<int>&vis, vector<int>adj[], int &count){
        vis[i] = 1;
        queue<int>q;
        q.push(i);
        int nodes = 0;
        int edge = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodes++;
            for(auto val : adj[node]){
                if(!vis[val]){
                    vis[val] = 1;
                    q.push(val);
                }
                edge++;
            }
        }
        if(nodes*(nodes-1) == edge) count++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //Convert to adjacency list
        vector<int>adj[n];
        for(auto val : edges){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        vector<int>vis(n, 0);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, adj, count);
            }
        }
        return count;
    }
};