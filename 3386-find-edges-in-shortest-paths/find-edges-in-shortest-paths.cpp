class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool>ans(edges.size(), false);
        vector<long long>dist(n, 1e10);
        vector<pair<long long, long long>>adj[n];
        for(auto val : edges) {
            adj[val[0]].push_back({val[1], val[2]});
            adj[val[1]].push_back({val[0], val[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            long long node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]) {
                long long adjNode = val.first;
                long long edgeWt = val.second;
                if(wt + edgeWt < dist[adjNode]) {
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        // for(auto val : dist) cout<<val<<" ";
        long long k = dist[n-1];
        vector<long long>dist1(n, 1e10);
        dist1[n-1] = 0;
        pq.push({0, n-1});
        while(!pq.empty()) {
            long long node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]) {
                long long adjNode = val.first;
                long long edgeWt = val.second;
                if(dist1[adjNode] > wt + edgeWt) {
                    dist1[adjNode] = wt + edgeWt;
                    pq.push({dist1[adjNode], adjNode});
                }
            }
        }
        // for(auto val : dist1) cout<<val<<" ";
        for(long long i = 0; i<edges.size(); i++) {
            if(dist[edges[i][0]] + dist1[edges[i][1]] + edges[i][2] == k) {
                ans[i] = true;
            }
            else if(dist1[edges[i][0]] + dist[edges[i][1]] + edges[i][2] == k) {
                ans[i] = true;
            }
        }
        return ans;
    }
};