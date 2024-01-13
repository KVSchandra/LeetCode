class Solution {
private:
    void bfs(int i, vector<int>&vis, vector<int>adj[], queue<int>&q){
        vis[i] = 1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto val : adj[node]){
                if(!vis[val]){
                    vis[val] = 1;
                    q.push(val);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //CONVERT TO ADJACENCY LIST
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int>q;
        int count = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, adj, q);
                count++;
            }
        }
        return count;
    }
};