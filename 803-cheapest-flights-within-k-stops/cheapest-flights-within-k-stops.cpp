class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<pair<int, int>>adj[n];
        for(auto val : flights){
            adj[val[0]].push_back({val[1], val[2]});
        }
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        // {k, {node, cost}}
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            int stop = pq.top().first;
            int node = pq.top().second.first;
            int cost = pq.top().second.second;
            if(stop > k) break;
            pq.pop();
            for(auto val : adj[node]){
                int adjNode = val.first;
                int wt = val.second;
                if(dist[adjNode] > cost + wt && stop <= k){
                    dist[adjNode] = cost + wt;
                    pq.push({stop+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};