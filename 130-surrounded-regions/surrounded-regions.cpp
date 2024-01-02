class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(board[i][j] == 'O'){
                        vis[i][j] = 1;
                        q.push({i, j});
                        board[i][j] = '#';
                    }
                }
            }
        }
        vector<int>v = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int Dx = x + v[i];
                int Dy = y + v[i+1];
                if(Dx>=0 && Dy>=0 && Dx<n && Dy<m && !vis[Dx][Dy] && board[Dx][Dy]=='O'){
                    vis[Dx][Dy] = 1;
                    board[Dx][Dy] = '#';
                    q.push({Dx, Dy});
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == '#' && vis[i][j] == 1){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};