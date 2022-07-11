class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        vector<pair<int, int>> dp(N, {0, 0});
        dp[0].first = -1*prices[0];
        dp[0].second = 0;
        for(int i=1; i<N; i++) {
            dp[i].first=max(dp[i-1].first, dp[i-1].second-prices[i]);
            dp[i].second=max(dp[i-1].second, dp[i-1].first+prices[i]-fee);
        }
        return dp[N-1].second;
    }
};