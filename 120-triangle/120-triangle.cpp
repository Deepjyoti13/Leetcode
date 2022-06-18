class Solution {
    int helper(vector<vector<int>>& triangle, int r, int c, int N, vector<vector<int>>& dp) {
        if(r==N-1) return triangle[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c] = triangle[r][c] + min(helper(triangle, r+1, c, N, dp), (helper(triangle, r+1, c+1, N, dp)));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return helper(triangle, 0, 0, N, dp);
    }
};