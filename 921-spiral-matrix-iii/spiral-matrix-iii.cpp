class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int k = rows * cols;
        int c = 0;
        int count = 0;
        ans.push_back({rStart, cStart});
        k--;
        while(k) {
            if(c % 2 == 0) {
                count++;
            }
            for(int i = 0; i < count; i++) {
                rStart += dir[c%4].first;
                cStart += dir[c%4].second;
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                    k--;
                    if(k == 0) break;
                }
            }
            c++;
        }
        return ans;
    }
};