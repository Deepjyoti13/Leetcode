class Solution {
    // int helper(vector<int>& nums, int target, int N, vector<int>& dp) {
    //     if(!target) return 1;
    //     if(target<0) return 0;
    //     if(dp[target]) return dp[target];
    //     for(int i=0; i<N; i++) {
    //         if(target>=nums[i])
    //             dp[target]+=helper(nums, target-nums[i], N, dp);
    //     }
    //     return dp[target];
    // }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int N = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0]=1;
        // return helper(nums, target, N, dp);
        for(int i=1; i<=target; i++) {
            for(int j=0; j<N; j++) {
                if(i>=nums[j]) {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};