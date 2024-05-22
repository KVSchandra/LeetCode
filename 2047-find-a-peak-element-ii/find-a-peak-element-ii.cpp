class Solution {
public:
    int findMaxIndex(int col, int n, int m, vector<vector<int>>&mat) {
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = 0; i<n; i++) {
            if(maxi < mat[i][col]) {
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int maxRowInd = findMaxIndex(mid, n, m, mat);
            int left = -1, right = -1;
            if(mid-1 >= 0) {
                left = mat[maxRowInd][mid-1];
            }
            if(mid+1 < m) {
                right = mat[maxRowInd][mid+1];
            }
            if(mat[maxRowInd][mid] > left && mat[maxRowInd][mid] > right) {
                return {maxRowInd, mid};
            }
            else if(mat[maxRowInd][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};