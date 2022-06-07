class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        int N=prices.size(), res=0;
        if(N<2) return 0;
        vector<vector<int>> dp(x+1, vector<int>(N, 0));
        for(int i=1; i<=x; i++) {
            int mx = dp[i-1][0]-prices[0];
            for(int j=1; j<N; j++) {
                mx=max(mx, dp[i-1][j-1]-prices[j-1]);
                dp[i][j]=max(dp[i][j-1], mx+prices[j]);
                // for(int k=0; k<j; k++) {
                //     dp[i][j]=max(dp[i][j], dp[i-1][k]+prices[j]-prices[k]);
                // }
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};