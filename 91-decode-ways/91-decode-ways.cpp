class Solution {
    int helper(string &s, int m, int* dp) {
        if(m==0) return 1;
        if(s[m-1]=='0') {
            if(m==1 || (s[m-2]!='1' && s[m-2]!='2')) return 0;
        }
        if(m==1) {
            return 1;
        }
        if(dp[m]) return dp[m];
        int ans=0;  
        int a = s[m-2];
        int b = s[m-1];
        if(b!='0') {
            ans+=helper(s, m-1, dp);
        }
        if(a=='1' || a=='2' && b<='6') {
            ans+=helper(s, m-2, dp);
        }
        return dp[m] = ans;
    }
public:
    int numDecodings(string s) {
        int size = s.length();
        int* dp = new int[size+1];
        for(int i=0; i<=size; i++) dp[i]=0;
        return helper(s, size, dp);
    }
};