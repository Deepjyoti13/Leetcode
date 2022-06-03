class Solution {
    void DFS(vector<vector<char>>& board, int i, int j, int N, int M) {
        board[i][j]='#';
        if(i+1<N && board[i+1][j]=='O') DFS(board, i+1, j, N, M);
        if(i-1>=0 && board[i-1][j]=='O') DFS(board, i-1, j, N, M);
        if(j+1<M && board[i][j+1]=='O') DFS(board, i, j+1, N, M);
        if(j-1>=0 && board[i][j-1]=='O') DFS(board, i, j-1, N, M);
    }
public:
    void solve(vector<vector<char>>& board) {
        int N = board.size(), M = board[0].size();
        for(int i=0; i<M; i++) {
            if(board[0][i]=='O')
                board[0][i]='#';
            if(board[N-1][i]=='O')
                board[N-1][i]='#';
        }
        for(int i=0; i<N; i++) {
            if(board[i][0]=='O')
                board[i][0]='#';
            if(board[i][M-1]=='O')
                board[i][M-1]='#';
        }
        for(int i=0; i<M; i++) {
            if(board[0][i]=='#')
                DFS(board, 0, i, N, M);
            if(board[N-1][i]=='#')
                DFS(board, N-1, i, N, M);
        }
        for(int i=0; i<N; i++) {
            if(board[i][0]=='#')
                DFS(board, i, 0, N, M);
            if(board[i][M-1]=='#')
                DFS(board, i, M-1, N, M);
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#') {
                    board[i][j]='O';
                }
            }
        }
    }
};