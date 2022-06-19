class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1), count(N, 1);
        int mx = 1, cnt=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]) {
                    if(dp[i]<1+dp[j]) {
                        dp[i] = 1+dp[j];
                        count[i] = count[j];
                    }
                    else if(dp[i]==1+dp[j])
                        count[i]+=count[j];
                }
            }
            mx = max(dp[i], mx);
        }
        for(int i=0; i<N; i++) {
            if(mx==dp[i]) cnt+=count[i];
        }
        return cnt;
    }
};