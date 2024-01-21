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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int>mp;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                }
                else {
                    ds.unionByRank(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<string>mergeMails[n];
        for(auto val : mp){
            string mail = val.first;
            int node = ds.findUParent(val.second);
            mergeMails[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i = 0; i<n; i++){
            if(mergeMails[i].size() == 0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto val : mergeMails[i]){
                temp.push_back(val);
            }
            sort(temp.begin()+1, temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};