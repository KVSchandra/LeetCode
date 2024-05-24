class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(auto val : roads) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int a = 0;
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) a--;
                a += adj[i].size() + adj[j].size();
                maxi = max(maxi, a);
            }
        }
        return maxi;
    }
};