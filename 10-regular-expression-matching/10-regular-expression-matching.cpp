class Solution {
public:
    bool isMatch(string s, string p) {
        int M = p.length(), N=s.length();
        vector<vector<bool>> dp(M+1, vector<bool>(N+1, false));
        dp[0][0]=true;
        for(int i=0; i<M; i++) {
            if(p[i]=='*') dp[i+1][0]=dp[i-1][0];
        }
        for(int i=1; i<=M; i++) {
            for(int j=1; j<=N; j++) {
                if(p[i-1]==s[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='.') {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*') {
                    dp[i][j]=dp[i-2][j];
                    if(p[i-2]==s[j-1] || p[i-2]=='.') {
                        dp[i][j]=dp[i][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[M][N];
    }
};