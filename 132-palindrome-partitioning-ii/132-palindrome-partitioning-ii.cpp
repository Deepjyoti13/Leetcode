class Solution {
    int dp[2001];
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
        if(dp[i]) return dp[i];
        if(isPalindrome(s, i, j)) return 0;
        int res=INT_MAX;
        for(int k=i; k<j; k++) {
            if (isPalindrome(s, i, k))
 				res = min(res, 1 + helper(s, k + 1, j));
        }
        return dp[i]=res;
    }
public:
    int minCut(string s) {
        int N = s.length();
        memset(dp, 0, sizeof(dp));
        return helper(s, 0, N-1);
    }
};