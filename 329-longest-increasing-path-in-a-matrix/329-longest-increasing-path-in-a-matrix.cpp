class Solution {
    int res;
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int M, int N) {
        if(dp[i][j]) return dp[i][j];
        int ans=1;
        if(i+1<M && matrix[i+1][j]>matrix[i][j])
            ans = max(ans, 1+DFS(matrix, dp, i+1, j, M, N));
        if(j+1<N && matrix[i][j+1]>matrix[i][j])
            ans = max(ans, 1+DFS(matrix, dp, i, j+1, M, N));
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
            ans = max(ans, 1+DFS(matrix, dp, i-1, j, M, N));
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
            ans = max(ans, 1+DFS(matrix, dp, i, j-1, M, N));
        res = max(ans, res);
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        res = 0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(!dp[i][j])
                    DFS(matrix, dp, i, j, M, N);
            }
        }
        return res;
    }
};