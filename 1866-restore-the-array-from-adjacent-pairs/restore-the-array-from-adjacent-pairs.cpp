class Solution {
public:
    void solve(int i, unordered_map<int, int>&vis, unordered_map<int, vector<int>>&adj, vector<int>&ans) {
        ans.push_back(i);
        vis[i] = 1;
        for(auto val : adj[i]) {
            if(vis.find(val) == vis.end()) {
                solve(val, vis, adj, ans);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>adj;
        for(auto val : adjacentPairs) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        int a = -1;
        for(auto val : adj) {
            if(val.second.size() == 1) {
                a = val.first;
                break;
            }
        }
        unordered_map<int, int>vis;
        vector<int>ans;
        solve(a, vis, adj, ans);
        return ans;
    }
};