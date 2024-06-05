class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<long long>pq;
        long long x = 0;
        for(int i = 1; i<matrix.size(); i++) matrix[i][0] ^= matrix[i-1][0];
        for(int i = 1; i<matrix[0].size(); i++) matrix[0][i] ^= matrix[0][i-1];
        for(int i = 1; i<matrix.size(); i++) {
            for(int j = 1; j<matrix[0].size(); j++) {
                matrix[i][j] = matrix[i][j] ^ matrix[i-1][j] ^ matrix[i][j-1] ^ matrix[i-1][j-1]; 
            }
        }
        for(auto val : matrix) {
            for(auto val1 :val) {
                // cout << val1 << " ";
                pq.push(val1);
            }
            // cout << endl;
        }
        k--;
        while(!pq.empty() && k--) pq.pop();
        return pq.top();
    }
};