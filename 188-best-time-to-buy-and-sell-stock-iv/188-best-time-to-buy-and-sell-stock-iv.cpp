class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        int N=prices.size(), res=0;
        if(N<2) return 0;
        vector<vector<int>> dp(x+1, vector<int>(N, 0));
        for(int i=1; i<=x; i++) {
            for(int j=1; j<N; j++) {
                dp[i][j]=dp[i][j-1];
                for(int k=0; k<j; k++) {
                    dp[i][j]=max(dp[i][j], dp[i-1][k]+prices[j]-prices[k]);
                }
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};