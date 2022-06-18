class Solution {
    int dp[70][70][70] = {};
    int helper(vector<vector<int>>& grid, int i, int j1, int j2, int M, int N) {
        if(j1<0 || j2<0 || j1>=N || j2>=N) return -1e8;
        if(i==M-1) {
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int mx = -1e8;
        for(int dj1=-1; dj1<=+1; dj1++) {
            for(int dj2=-1; dj2<=+1; dj2++) {
                int res = grid[i][j1];
                if(j1!=j2)
                    res+=grid[i][j2];
                res+=helper(grid, i+1, j1+dj1, j2+dj2, M, N);
                mx = max(res, mx);
            }
        }
        return dp[i][j1][j2] = mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, N-1, M, N);
    }
};