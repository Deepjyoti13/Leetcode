class Solution {
    int helper(vector<int>& nums, int N, vector<int>& dp) {
        if(N==0) return 0;
        if(N==1) return nums[0];
        if(dp[N]!=-1) return dp[N];
        return dp[N] = max(nums[N-1]+helper(nums, N-2, dp), helper(nums, N-1, dp));
    }
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N+1, -1);
        return helper(nums, N, dp);
    }
};