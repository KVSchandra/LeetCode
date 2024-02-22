class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        vector<int>inDegree(n+1, 0);
        vector<int>outDegree(n+1, 0);
        for(auto val : trust){
            inDegree[val[1]]++;
            outDegree[val[0]]++;
        }
        int ans = -1;
        for(auto val : inDegree) cout<<val<<" ";
        for(int i = 1; i<=n; i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0) return i;
        }
        return -1;
    }
};