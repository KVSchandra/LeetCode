class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<char>>&board){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        vector<int>dir = {0, -1, 0, 1, 0};
        for(int k = 0; k<4; k++){
            int dx = i + dir[k];
            int dy = j + dir[k+1];
            if(dx<n && dy<m && dx>=0 && dy>=0 && !vis[dx][dy] && board[dx][dy] == 'X'){
                dfs(dx, dy, vis, board);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size();
        vector<vector<int>>vis(n ,vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    dfs(i, j, vis, board);
                    count++;
                }
            }
        }
        return count;
    }
};