class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        // vector<pair<int, int>> dp(N, {0, 0});
        pair<int, int> calc;
        calc.first = -1*prices[0];
        calc.second = 0;
        // dp[0].first = -1*prices[0];
        // dp[0].second = 0;
        pair<int, int> curr;
        for(int i=1; i<N; i++) {
            curr.first=max(calc.first, calc.second-prices[i]);
            curr.second=max(calc.second, calc.first+prices[i]-fee);
            calc = curr;
        }
        return calc.second;
    }
};