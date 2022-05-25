class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        vector<vector<bool>> dp(N+1, vector<bool>(N+1, false));
        int count=0;
        // for 1 element
        for(int i=0; i<N; i++) {
            dp[i][i]=true;
            count++;
        }
        // for 2 elements
        for(int i=0; i<N-1; i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1]=true;
                count++;
            }
        }
        // for 3+ elements
        for(int k=3; k<=N; k++) {
            for(int i=0; i<N-k+1; i++) {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j]=true;
                    count++;
                }
            }
        }
        return count;
    }
};