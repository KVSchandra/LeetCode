class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n];
        for(auto val : roads){
            adj[val[0]].push_back({val[1], val[2]});
            adj[val[1]].push_back({val[0], val[2]});
        }
        vector<long long>dist(n, 1e15);
        vector<int>ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]){
                int adjNode = val.first;
                long long edgeWt = val.second;
                if(dist[adjNode] > wt + edgeWt){
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == wt + edgeWt){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] ;
    }
};