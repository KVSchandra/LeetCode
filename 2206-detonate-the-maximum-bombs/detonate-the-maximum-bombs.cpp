class Solution {
public:
    int dfs(int i, vector<int>adj[], vector<int>&vis, int &count){
        vis[i] = 1;
        count++;
        for(auto val : adj[i]){
            if(!vis[val]){
                dfs(val, adj, vis, count);
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int>adj[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i != j){
                    double dist = sqrt(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2));
                    if(dist <= bombs[i][2]){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            vector<int>vis(n, 0);
            int count = 0;
            dfs(i, adj, vis, count);
            maxi = max(maxi, count);
        }
        return maxi;
    }
};