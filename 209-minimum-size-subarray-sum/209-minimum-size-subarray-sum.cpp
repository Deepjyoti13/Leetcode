class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // nums.push_back(0);
        int res = INT_MAX-100;
        int N = nums.size();
        int left=0, right=0, sum=0;
        while(right<N) {
            sum+=nums[right];
            while(sum>=target) {
                res = min(res, right-left+1);
                sum-=nums[left++];
            }
            if(sum<target && right+1==N)
                return res==INT_MAX-100?0:res;
            right++;
        }
        return res;
    }
};