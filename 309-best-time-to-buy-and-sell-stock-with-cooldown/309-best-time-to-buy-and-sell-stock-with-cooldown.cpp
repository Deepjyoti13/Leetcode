class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N=prices.size();
        vector<vector<int>> dp(N, vector<int>(3, 0));
        dp[0][0]=0-prices[0];
        for(int i=1; i<N; i++) {
            //buy
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i]);

            //sell
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);

            //cooldown
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
            cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        return max(dp[N-1][1], dp[N-1][2]);
    }
};