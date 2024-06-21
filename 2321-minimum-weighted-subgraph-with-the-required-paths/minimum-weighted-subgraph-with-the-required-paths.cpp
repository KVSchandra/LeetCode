#define ll long long
class Solution {
public:
    vector<ll> dijkstra(ll src, const vector<vector<pair<int, ll>>> &adj) {
        ll n = adj.size();
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
        vector<ll> dist(n, 1e18);
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            ll d = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto val : adj[node]){
                ll adjNode = val.first;
                int edgeWt = val.second;
                if(d + edgeWt < dist[adjNode]){
                    dist[adjNode] = d + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, ll>>> adj(n), rev(n);
        for(auto &val : edges) {
            adj[val[0]].push_back({val[1], val[2]});
            rev[val[1]].push_back({val[0], val[2]});
        }
        vector<ll> v1 = dijkstra(src1, adj);
        vector<ll> v2 = dijkstra(src2, adj);
        vector<ll> v3 = dijkstra(dest, rev);
        ll mini = 1e18;
        for(ll i = 0; i < n; i++) {
            if(v1[i] != 1e18 && v2[i] != 1e18 && v3[i] != 1e18) {  
                mini = min(mini, (ll)v1[i] + v2[i] + v3[i]);
            }
        }
        if(mini >= 1e18) return -1;
        return mini;
    }
};