class Solution {
    int DFS(vector<vector<int>>& grid, int i, int j, int M, int N) {
        grid[i][j]=2;
        int sum=1;
        if(i+1<M && grid[i+1][j]==1)
            sum+=DFS(grid, i+1, j, M, N);
        if(j+1<N && grid[i][j+1]==1)
            sum+=DFS(grid, i, j+1, M, N);
        if(i-1>=0 && grid[i-1][j]==1)
            sum+=DFS(grid, i-1, j, M, N);
        if(j-1>=0 && grid[i][j-1]==1)
            sum+=DFS(grid, i, j-1, M, N);
        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M=grid.size(), N=grid[0].size(), result=0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]==1) {
                    int sum = DFS(grid, i, j, M, N);
                    result = max(sum, result);
                }
            }
        }
        return result;
    }
};