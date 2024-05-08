class Solution {
public:
    long long count = 0;
    long long dfs(int i, int k, vector<int>&vis, vector<int>adj[], vector<int>&values) {
        vis[i] = 1;
        long long sum = 0;
        for(auto val : adj[i]) {
            if(!vis[val]) {
                sum += dfs(val, k, vis, adj, values);
            }
        }
        sum += values[i];
        if(sum%k == 0) {count++; return 0;}
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto val : edges) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        vector<int>vis(n, 0);
        dfs(0, k, vis, adj, values);
        return count;
    }
};