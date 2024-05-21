class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>>v(mat.size()+mat[0].size());
        for(int i = 0; i<mat.size(); i++) {
            for(int j = 0; j<mat[0].size(); j++) {
                v[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(int i = 0; i<v.size(); i++) {
            if((i & 1) == 0) reverse(v[i].begin(), v[i].end());
            for(auto val : v[i]) ans.push_back(val);
        }
        return ans;
    }
};