class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length()==0)
            return (s.length()==0);
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[0][0]=1;
        for(int i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else if(p[j-1]==s[i-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[s.length()][p.length()];
      
    }
};