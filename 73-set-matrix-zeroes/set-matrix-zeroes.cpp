class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            auto val = q.front();
            q.pop();
            for(int i = 0; i<n; i++) {
                matrix[i][val.second] = 0;
            }
            for(int j = 0; j<m; j++) {
                matrix[val.first][j] = 0;
            }
        }
    }
};