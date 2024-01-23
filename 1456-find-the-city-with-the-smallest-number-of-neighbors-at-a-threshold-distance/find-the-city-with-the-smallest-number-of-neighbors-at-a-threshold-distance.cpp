class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n, vector<int>(n, 1e9));
        for(auto val : edges){
            int u = val[0];
            int v = val[1];
            int wt = val[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        for(int i = 0; i<n; i++){
            matrix[i][i] = 0;
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(i == k || j == k) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int mini = n;
        int ans;
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(matrix[i][j] <= distanceThreshold) count++;
            }
            if(mini >= count){
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};