class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int z=edges[i][0];
            int y=edges[i][1];
            indegree[z]++;
            indegree[y]++;
            mp[z].push_back(y);
            mp[y].push_back(z);
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==1)q.push(i);
        }
        vector<int>ans;
        if(n==1)ans.push_back(0);
        while(n>2){
            int s=q.size();
            n-=s;
            while(s--){
                int u=q.front();
                q.pop();
                for(int & k:mp[u]){
                indegree[k]--;
                if(indegree[k]==1)q.push(k);

                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;


    }
};