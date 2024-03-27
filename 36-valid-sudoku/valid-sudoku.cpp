class Solution {
public:
    bool isValid(int row, int col, char k, vector<vector<char>>&board) {
        board[row][col] = '#';
        for(int i = 0; i<9; i++) {
            if(i != col && board[row][i] == k) return false;
            if(i != row && board[i][col] == k) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == k) return false;
        }
        board[row][col] = k;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                if(board[i][j] != '.') {
                    if(isValid(i, j, board[i][j], board) == false) return false;
                }
            }
        }
        return true;
    }
};