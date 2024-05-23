class Solution {
public:
    vector<int>topoSort(vector<int>&inDegree, vector<int>adj[]) {
        vector<int>topo;
        queue<int>q;
        for(int i = 0; i<inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto val : adj[node]) {
                inDegree[val]--;
                if(inDegree[val] == 0) {
                    q.push(val);
                }
            }
        }
        return topo;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses], inDegree(numCourses);
        for(auto val : prerequisites) {
            adj[val[1]].push_back(val[0]);
            inDegree[val[0]]++;
        }
        vector<int>topo = topoSort(inDegree, adj);
        if(topo.size() != numCourses) return {};
        return topo;
    }
};