class Solution {
public:
    bool solve(int ind, int i, int j,string &word, vector<vector<char>> &board, vector<vector<int>>&vis, vector<vector<int>>&pathVis){
        int n = board.size();
        int m = board[0].size();
        if(ind == word.size()-1) return true;
        vis[i][j] = 1;
        pathVis[i][j] = 1;
        vector<int>dir = {0, 1, 0, -1, 0};
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy] && board[dx][dy] == word[ind+1]){
                if(solve(ind+1, dx, dy, word, board, vis, pathVis)) return true;
            }
        }
        vis[i][j] = 0;
        pathVis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>pathVis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(solve(0, i, j, word, board, vis, pathVis)) return true;
                }
            }
        }
        return false;
    }
};