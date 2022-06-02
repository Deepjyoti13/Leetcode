class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, res=INT_MAX, sum=0, N=nums.size();
        while(r<N) {
            sum+=nums[r++];
            while(sum>=target) {
                sum-=nums[l++];
                res = min(res, r-l+1);
            }
        }
        return res==INT_MAX?0:res;
    }
};