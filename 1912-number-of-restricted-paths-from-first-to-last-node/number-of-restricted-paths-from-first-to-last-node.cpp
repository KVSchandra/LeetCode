class Solution {
public:
    int mod = 1e9+7;

    int dfs(int i, vector<int>&dist, vector<pair<int, int>>adj[], vector<int>&dp) {
        if(i == dist.size()-1) return 1;
        if(dp[i] != -1) return dp[i];
        int maxi = 0;
        for(auto val : adj[i]) {
            if(dist[i] > dist[val.first]) {
                maxi = (maxi + dfs(val.first, dist, adj, dp))%mod;
            }
        }
        return dp[i] = maxi%mod;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>>adj[n+1];
        for(auto val : edges) {
            adj[val[0]].push_back({val[1], val[2]});
            adj[val[1]].push_back({val[0], val[2]});
        }
        vector<int>dist(n+1, INT_MAX);
        dist[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, n});
        while(!pq.empty()) {
            int node = pq.top().second;
            int edgeWt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]) {
                int adjNode = val.first;
                int wt = val.second;
                if(dist[adjNode] > wt + edgeWt) {
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        vector<int>dp(n+1, -1);
        return dfs(1, dist, adj, dp);
    }
};