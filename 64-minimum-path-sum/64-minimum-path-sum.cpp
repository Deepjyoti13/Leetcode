class Solution {
    int helper(vector<vector<int>>& grid, int i, int j, int M, int N, vector<vector<int>>& dp) {
        if(i==M-1 && j==N-1) return dp[i][j] = grid[i][j];
        if(dp[i][j]) return dp[i][j];
        int op1=INT_MAX, op2=INT_MAX;
        if(i+1<M)
            op1=helper(grid, i+1, j, M, N, dp);
        if(j+1<N)
            op2=helper(grid, i, j+1, M, N, dp);
        return dp[i][j] = grid[i][j]+min(op1, op2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M=grid.size(), N=grid[0].size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        return helper(grid, 0, 0, M, N, dp);
    }
};