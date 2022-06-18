class Solution {
    int helper(int i, int j, int M, int N, vector<vector<int>>& dp) {
        if(i>=M || j>=N) return 0;
        if(i==M-1 || j==N-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = helper(i+1, j, M, N, dp)+helper(i, j+1, M, N, dp);
    }
public:
    int uniquePaths(int m, int n) {
        if(n<m) {
            n=n+m;
            m=n-m;
            n=n-m;
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, m, n, dp);
    }
};