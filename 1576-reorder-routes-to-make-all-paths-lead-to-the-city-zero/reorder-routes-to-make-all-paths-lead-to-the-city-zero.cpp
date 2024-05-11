class Solution {
public:
    int count = 0;
    void bfs(int i, vector<int>&vis, vector<int>adj1[], vector<int>adj2[]) {
        queue<int>q;
        q.push(i);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                vis[node] = 1;
                for(auto val : adj1[node]) {
                    if(!vis[val]) {
                        count++;
                        q.push(val);
                    }
                }
                for(auto val : adj2[node]) {
                    if(!vis[val]) {
                        q.push(val);
                    }
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>vis(n, 0);
        vector<int>adj1[n], adj2[n];
        for(auto val : connections) {
            adj1[val[0]].push_back(val[1]);
            adj2[val[1]].push_back(val[0]);
        }
        bfs(0, vis, adj1, adj2);
        return count;
    }
};