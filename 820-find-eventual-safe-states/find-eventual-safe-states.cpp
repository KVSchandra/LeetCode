class Solution {
public:
    bool dfs(int i, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&graph) {
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto val : graph[i]){
            if(!vis[val]){
                if(dfs(val, vis, pathVis, graph)) return true;
            }
            else if(pathVis[val]){
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>pathVis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, graph);
            }
        }
        vector<int>ans;
        for(int i = 0;i<n; i++){
            if(!pathVis[i]) ans.push_back(i);   
        }
        return ans;
    }
};