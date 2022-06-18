class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int dp[N][N];
        for(int i=0; i<N; i++) dp[0][i] = matrix[0][i];
        for(int i=1; i<N; i++) {
            for(int j=0; j<N; j++) {
                dp[i][j] = dp[i-1][j];
                if(j>=1) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(j<N-1) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j]+=matrix[i][j];
            }
        }
        int mn = INT_MAX;
        for(int i=0; i<N; i++) {
            mn = min(mn, dp[N-1][i]);
        }
        return mn;
    }
};