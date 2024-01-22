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
    bool isSimilar(string &s1, string &s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        int count = 0;
        int a = -1; int b = -1;
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]) {
                count++;
                if(a == -1) a = i;
                else b = i;
            }
            if(count > 2) return false;
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return 1;
        DisjointSet ds(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isSimilar(strs[i], strs[j])){
                    ds.unionBySize(i, j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) count++;
        }
        for(auto val : ds.parent) cout<<val<<" ";
        return count;
    }
};