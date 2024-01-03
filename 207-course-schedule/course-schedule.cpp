class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);
        for(auto val : prerequisites){
            inDegree[val[1]]++;
        }
        vector<int>adj[numCourses];
        for(auto val : prerequisites){
            adj[val[0]].push_back(val[1]);
        }
        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto val : adj[node]){
                inDegree[val]--;
                if(inDegree[val] == 0) q.push(val);
            }
        }
        return (count == numCourses);
    }
};