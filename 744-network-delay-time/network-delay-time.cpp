class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<pair<int, int>>adj[n+1];
        for(auto val : times){
            adj[val[0]].push_back({val[1], val[2]});
        }
        vector<int>dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]){
                int adjNode = val.first;
                int edgeWt = val.second;
                if(dist[adjNode] > wt + edgeWt){
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        dist[0] = -1;
        int maxi = *max_element(dist.begin(), dist.end());
        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};