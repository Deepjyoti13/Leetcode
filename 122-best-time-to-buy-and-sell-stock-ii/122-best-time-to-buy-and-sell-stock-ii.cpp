class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0, right=1, res=0;
        while(right<prices.size()) {
            if(prices[left]>=prices[right]) {
                left=right;
                right++;
            }
            else {
                res+=prices[right]-prices[left];
                left++;
                right++;
            }
        }
        return res;
    }
};