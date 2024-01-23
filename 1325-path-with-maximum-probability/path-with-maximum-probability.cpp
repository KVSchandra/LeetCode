class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>>adj[n];
        int m = edges.size();
        for(int i = 0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>dist(n, -1);
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start_node});
        dist[start_node] = 1.0;
        while(!pq.empty()){
            int node = pq.top().second;
            double wt = pq.top().first;
            pq.pop();
            for(auto val : adj[node]){
                int adjNode = val.first;
                double edgeWt = val.second;
                if(dist[adjNode] < wt*edgeWt){
                    dist[adjNode] = wt*edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[end_node] < 0) return 0;
        return dist[end_node];
    }
};