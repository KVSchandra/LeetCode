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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k<4; k++){
                        int dx = i + dir[k];
                        int dy = j + dir[k+1];
                        if(dx>=0 && dy>=0 && dx<n && dy<n && grid[dx][dy] == 1){
                            int node = i*n + j;
                            int nextNode = dx*n + dy;
                            if(ds.findUParent(node) != ds.findUParent(nextNode)){
                                ds.unionBySize(node, nextNode);
                            }
                        }
                    }
                }
            }
        }
        int maxi = INT_MIN;
        unordered_map<int, int>mp;
        for(int i = 0; i<n*n; i++){
            mp[ds.findUParent(i)]++;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int count = 0;
                unordered_set<int>st;
                if(grid[i][j] == 0){
                    for(int k = 0; k<4; k++){
                        int dx = i + dir[k];
                        int dy = j + dir[k+1];
                        if(dx>=0 && dy>=0 && dx<n && dy<n && grid[dx][dy] == 1){
                            int node = i*n + j;
                            int nextNode = dx*n + dy;
                            st.insert(ds.findUParent(nextNode));
                        }
                    }
                }
                int ans = 0;
                for(auto val : st){
                    ans += ds.size[val];
                }
                maxi = max(maxi, ans + 1);
            }
        }
        //If all the nodes are 1
        bool flag = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false) maxi = n*n;
        return maxi;
    }
};