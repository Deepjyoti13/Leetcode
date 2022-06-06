class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> dp1(N, 0);
        vector<int> dp2(N, 0);
        int mn=prices[0], res=0;
        dp1[0]=0, dp2[N-1]=0;
        for(int i=1; i<N; i++) {
            mn = min(mn, prices[i]);
            dp1[i]=max(prices[i]-mn, dp1[i-1]);
        }
        mn = prices[N-1];
        for(int i=N-2; i>=0; i--) {
            mn = max(mn, prices[i]);
            dp2[i]=max(dp2[i+1], mn-prices[i]);
            res = max(dp1[i]+dp2[i], res);
        }
        
        return res;
    }
};

