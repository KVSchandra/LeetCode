class Solution {
public:
    void dfs2(int node, int parent, vector<int>adj[], vector<int>&count, vector<int>&ans, int n) {
        for(auto val : adj[node]) {
            if(val != parent) {
                ans[val] = ans[node] - count[val] + n - count[val];
                dfs2(val, node, adj, count, ans, n);
            }
        }
    }

    void dfs(int node, int parent, vector<int>adj[], vector<int>&count, vector<int>&ans) {
        for(auto val : adj[node]) {
            if(val != parent) {
                dfs(val, node, adj, count, ans);
                count[node] += count[val];
                ans[node] += ans[val] + count[val];
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>count(n, 1); 
        vector<int>ans(n, 0);   

        for(auto &val : edges) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        dfs(0, -1, adj, count, ans);
        dfs2(0, -1, adj, count, ans, n);
        return ans;
    }


};
