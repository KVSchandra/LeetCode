class DisjointSet{
    public:
    vector<int>rank, parent;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = INT_MIN;
        int maxCol = INT_MIN;
        for(auto val : stones){
            maxRow = max(maxRow, val[0]);
            maxCol = max(maxCol, val[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int>mp;
        for(auto val : stones){
            int row = val[0];
            int col = val[1] + maxRow + 1;
            ds.unionByRank(row, col);
            mp[row] = 0;
            mp[col] = 0;
        }
        int count = 0;
        for(auto val : mp){
            if(ds.findUParent(val.first) == val.first) count++;
        }
        return stones.size() - count; 
    }
};