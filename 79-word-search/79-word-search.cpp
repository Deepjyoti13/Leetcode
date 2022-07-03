class Solution {
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int k, int M, int N, int W) {
        if(k==W) return true;
        if(i<0 || j<0 || i>=M || j>=N || k>W || board[i][j] == '0' || board[i][j]!=word[k])
            return false;
        board[i][j] = '0';
        bool res =  DFS(board, word, i+1, j, k+1, M, N, W) ||
                    DFS(board, word, i, j+1, k+1, M, N, W) ||
                    DFS(board, word, i-1, j, k+1, M, N, W) ||
                    DFS(board, word, i, j-1, k+1, M, N, W);
        board[i][j] = word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size(), N = board[0].size(), W = word.size();
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]==word[0] && DFS(board, word, i, j, 0, M, N, W))
                    return true;
            }
        }
        return false;
    }
};