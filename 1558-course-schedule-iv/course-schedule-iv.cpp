// Yeaaaaaaaaaaahhhhhhhhhhhhhhh......400th question


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>>matrix(n, vector<int>(n, 1e9));
        for(auto val : prerequisites){
            matrix[val[0]][val[1]] = 1;
        }
        for(int i = 0; i<n; i++){
            matrix[i][i] = 0;
        }
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(auto val : queries){
            if(matrix[val[0]][val[1]] != 1e9){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};