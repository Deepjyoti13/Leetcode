class Solution {
    int helper(vector<int>& nums, int i, int N, vector<vector<int>>& dp) {
        if(i>=N) return 0;
        if(i==N-1) return nums[i];
        if(dp[i][N]) return dp[i][N];
        return dp[i][N] = max(nums[i]+min(helper(nums, i+2, N, dp), helper(nums, i+1, N-1, dp)),
                  nums[N-1]+min(helper(nums, i, N-2, dp), helper(nums, i+1, N-1, dp)));
        
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        int sum=0;
        sum=accumulate(nums.begin(), nums.end(), sum);
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        int count = 0;
        int res = helper(nums, 0, N, dp);
        return res>=sum-res;
    }
};