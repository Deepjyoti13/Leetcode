class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        nums.push_back(0);
        int res = INT_MAX-100;
        int N = nums.size();
        int left=0, right=0, sum=0;
        while(right<N) {
            if(sum>=target) {
                res = min(res, right-left);
                sum-=nums[left++];
            }
            else if(sum<target) {
                sum+=nums[right];
                right++;
                if(sum<target && right==N)
                    return res==INT_MAX-100?0:res;
            }
        }
        return res;
    }
};