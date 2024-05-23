class Solution {
public:
    vector<int>topoSort(vector<int>&inDegree, vector<int>adj[]) {
        vector<int>topo;
        queue<int>q;
        for(int i = 0; i<inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto val : adj[node]) {
                inDegree[val]--;
                if(inDegree[val] == 0) {
                    q.push(val);
                }
            } 
        }
        return topo;
    }

    //REVERSE THE GRAPH, because we need 0 outdegree instead of 0 inDegree
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        vector<int>inDegree(n);
        for(int i = 0; i<n; i++) {
            for(auto val : graph[i]) {
                adj[val].push_back(i);
                inDegree[i]++;
            }
        }
        vector<int>topo = topoSort(inDegree, adj);
        sort(topo.begin(), topo.end());
        return topo;
    }
};