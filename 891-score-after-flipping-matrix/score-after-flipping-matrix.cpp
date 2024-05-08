class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == 0) {
                        grid[i][j] = 1;
                    }
                    else grid[i][j] = 0;
                }
            }
        }
        for(int j = 0; j<grid[0].size(); j++) {
            int count = 0;
            for(int i = 0; i<grid.size(); i++) {
                if(grid[i][j] == 0) count++;
            }
            if(count > grid.size()/2)
            for(int i = 0; i<grid.size(); i++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                }
                else grid[i][j] = 0;
            }
        }
        int sum = 0;
        for(int i = 0; i<grid.size(); i++) {
            int count = 0;
            reverse(grid[i].begin(), grid[i].end());
            for(int j = 0; j<grid[0].size(); j++) {
                count += grid[i][j] * (1 << j);
            }
            sum += count;
        }
        return sum;
    }
};