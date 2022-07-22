class Solution {
public:
    int dp[46] = {0};
    int climbStairs(int n) {
        if(n<4) return n;
        if(dp[n]) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};