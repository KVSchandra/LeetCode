class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>inDegree(n, 0);
        for(auto val : edges){
            inDegree[val[1]]++;
        }
        int ans = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                ans = i;
                count++;
            }
        }
        if(count == 1) return ans;
        return -1;
    }
};