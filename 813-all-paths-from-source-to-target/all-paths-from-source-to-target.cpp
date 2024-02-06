class Solution {
public:
    void dfs(int i, vector<vector<int>>&graph, vector<int>&temp, vector<vector<int>>&ans){
        temp.push_back(i);
        if(i == graph.size() - 1) ans.push_back(temp);
        else{
            for(auto val : graph[i]){
                dfs(val, graph, temp, ans);
            }
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0, graph, temp, ans);
        return ans;
    }
};