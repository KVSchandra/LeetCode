class Solution {
public:
    bool isValid(int node, set<int>&st) {
        return (st.find(node) == st.end());
    }

    int dfs(int i, vector<int>&vis, set<int>&st, vector<int>adj[]) {
        int pick = 0;
        vis[i] = 1;
        for(auto val : adj[i]) {
            if(!vis[val] && isValid(val, st)) {
                pick += (1 + dfs(val, vis, st, adj));
            }
        }
        return pick;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        set<int>st;
        for(auto val : restricted) st.insert(val);
        for(auto val : edges) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        vector<int>vis(n, 0);
        int ans = dfs(0, vis, st, adj);
        return ans+1;
    }
};