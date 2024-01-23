class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>matrix(n+1, vector<int>(n+1, 1e9));
        for(int i = 1; i<n; i++){
            int u = i;
            int v = i+1;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        for(int i = 1; i<=n; i++){
            matrix[i][i] = 0;
        }
        if(x != y) {
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        }

        for(int k = 1; k<=n; k++){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // for(auto val : matrix){
        //     for(auto it : val){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        vector<int>ans(n, 0);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(matrix[i][j] != 1e9 && matrix[i][j] != 0)
                ans[matrix[i][j]-1]++;
            }
        }
        return ans;
    }
};