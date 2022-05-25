class Solution {
    int helper(string &text1, string &text2, int m, int n, int** dp) {
        if(m==0 || n==0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(text1[m-1]==text2[n-1])
            return dp[m][n] = 1+helper(text1, text2, m-1, n-1, dp);
        else {
            int a=helper(text1, text2, m-1, n, dp);
            int b=helper(text1, text2, m, n-1, dp);
            return dp[m][n] = max(a, b);
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string tmp = s;
        reverse(s.begin(), s.end());
        int** dp = new int*[n+1];
        for(int i=0; i<=n; i++) {
            dp[i] = new int[n+1];
            for(int j=0; j<=n; j++) {
                dp[i][j]=-1;
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        return helper(tmp, s, n, n, dp);
    }
};