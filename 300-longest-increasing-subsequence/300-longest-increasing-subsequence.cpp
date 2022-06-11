class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int N = nums.size();
        dp.push_back(nums[0]);
        int l=1;
        for(int i=1; i<N; i++) {
            if(nums[i]>dp.back()) {
                dp.push_back(nums[i]);
                l++;
            }
            else {
                int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[index] = nums[i];
            }
        }
        return l;
    }
};