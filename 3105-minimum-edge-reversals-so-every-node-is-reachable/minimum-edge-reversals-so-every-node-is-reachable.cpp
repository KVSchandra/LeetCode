class Solution {
public:
    static const int f = 1e5;
    vector<int>adj1[f], adj2[f];
    unordered_map<int, unordered_map<int, int>>dp;
    int dfs(int i, int parent) {
        int pick = 0, notPick = 0;
        if(dp[i].find(parent+1) != dp[i].end()) return dp[i][parent+1];
        for(auto &val : adj1[i]) {
            if(val != parent) pick += dfs(val, i);
        }
        for(auto &val : adj2[i]) {
           if(val != parent) notPick += 1 + dfs(val, i);
        }
        return dp[i][parent+1] = pick + notPick;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        for(auto val : edges) {
            adj1[val[0]].push_back(val[1]);
            adj2[val[1]].push_back(val[0]);
        }
        vector<int>ans(n, 0);
        for(int i = 0; i<n; i++) {
            int a = dfs(i, -1);
            ans[i] = a;
        }
        return ans;
    }
};