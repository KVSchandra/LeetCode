#define ll long long
class Solution {
public:
    ll dfs(ll i, vector<vector<ll>>& adj, vector<ll>& dp) {
        ll mini = INT_MAX;
        if(i == adj.size() - 1) return 0;
        if(dp[i] != -1) return dp[i];
        for(auto val : adj[i]) {
            mini = min(mini, 1 + dfs(val, adj, dp));
        }
        return dp[i] = mini;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<ll>> adj(n);
        for(ll i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);
        }
        for(auto val : queries) {
            vector<ll> dp(n, -1);
            adj[val[0]].push_back(val[1]);
            ll mini = dfs(0, adj, dp);
            ans.push_back(mini);
        }
        return ans;
    }
};