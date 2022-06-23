class Solution {
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for(int i=0; i<9; i++) {
            if(board[r][i]==ch) return false;
            if(board[i][c]==ch) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board) {
        for(int row = 0; row<9; row++) {
            for(int col = 0; col<9; col++) {
                if(board[row][col]=='.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        if(isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if(helper(board))
                                return true;
                            board[row][col] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};