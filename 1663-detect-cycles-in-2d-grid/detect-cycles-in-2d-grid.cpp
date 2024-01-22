class DisjointSet{
    public:
    vector<int>rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
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

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m + 1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i>0 && grid[i][j] == grid[i-1][j]){
                    int x = i*m + j;
                    int y = (i-1)*m + j;
                    if(ds.findUParent(x) != ds.findUParent(y)){
                        ds.unionByRank(x, y);
                    }
                    else return true;
                }
                if(j<m-1 && grid[i][j] == grid[i][j+1]){
                    int x = i*m + j;
                    int y = i*m + j + 1;
                    if(ds.findUParent(x) != ds.findUParent(y)){
                        ds.unionByRank(x, y);
                    }
                    else return true;
                }
            }
        }
        return false;
    }
};