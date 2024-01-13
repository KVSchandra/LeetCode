class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                        board[i][j] = '#';
                    }
                }
            }
        }
        vector<int> dir = {0, 1, 0, -1 ,0};
        while(!q.empty()){
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int dx = x + dir[i];
                    int dy = y + dir[i+1];
                    if(dx>=0 && dx<n && dy>=0 && dy<m && board[dx][dy] == 'O'){
                        board[dx][dy] = '#';
                        q.push({dx, dy});
                    }
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};