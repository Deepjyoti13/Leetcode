class Solution {
    void DFS(vector<vector<char>>& grid, int i, int j, int M, int N) {
        grid[i][j]='#';
        if(i+1<M && grid[i+1][j]=='1')
            DFS(grid, i+1, j, M, N);
        if(j+1<N && grid[i][j+1]=='1')
            DFS(grid, i, j+1, M, N);
        if(i-1>=0 && grid[i-1][j]=='1')
            DFS(grid, i-1, j, M, N);
        if(j-1>=0 && grid[i][j-1]=='1')
            DFS(grid, i, j-1, M, N);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int M=grid.size(), N=grid[0].size(), count=0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]=='1') {
                    DFS(grid, i, j, M, N);
                    count++;
                }
            }
        }
        return count;
    }
};