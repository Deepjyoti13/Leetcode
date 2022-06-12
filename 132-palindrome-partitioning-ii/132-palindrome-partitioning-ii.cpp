class Solution {
    int dp[2001][2001];
    bool isPalindrome(string& s, int i, int j) {
        if(i==j) return true;
        if(i>j) return false;
        while(i<j) {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string& s, int i, int j) {
        if(i>=j) return 0;
        if(dp[i][j]) return dp[i][j];
        if(isPalindrome(s, i, j)) return 0;
        int res=INT_MAX;
        for(int k=i; k<j; k++) {
            if (isPalindrome(s, i, k))
 				res = min(res, 1 + helper(s, k + 1, j));
            // res = min(res, 1+a+b);
        }
        return dp[i][j]=res;
    }
public:
    int minCut(string s) {
        int N = s.length();
        memset(dp, 0, sizeof(dp));
        // int** dp = new int*[N+1];
        // for(int i=0; i<=N; i++) {
        //     dp[i] = new int[N+1];
        //     for(int j=0; j<=N; j++)
        //         dp[i][j]=0;
        // }
        // vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        return helper(s, 0, N-1);
    }
};