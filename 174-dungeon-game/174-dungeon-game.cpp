class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[M-1][N-1] = min(0, dungeon[M-1][N-1]);
        for(int i=M-2; i>=0; i--) {
            dp[i][N-1] = dungeon[i][N-1]+dp[i+1][N-1]>=0?0:dungeon[i][N-1]+dp[i+1][N-1];
        }
        for(int j=N-2; j>=0; j--) {
            dp[M-1][j] = dungeon[M-1][j]+dp[M-1][j+1]>=0?0:dungeon[M-1][j]+dp[M-1][j+1];
        }
        for(int i=M-2; i>=0; i--) {
            for(int j=N-2; j>=0; j--) {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1])+dungeon[i][j];
                if(dp[i][j]>=0) dp[i][j]=0;
            }
        }
        return -dp[0][0]+1;
    }
};

// -2  -3   3
// -5  -10  1
// 10   30 -5
    
    
// -6   -4   -1
// -5   -10  -4
//  0    0   -5