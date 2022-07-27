class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int maxHere=nums[0];
        int N=nums.size();
        for(int i=1; i<N; i++) {
            maxHere= max(nums[i], maxHere+nums[i]);
            result = max(result, maxHere);
        }
        return result;
    }
};