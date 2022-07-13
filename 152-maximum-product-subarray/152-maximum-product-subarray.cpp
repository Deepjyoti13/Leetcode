class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int mx=res, mn=res, N=nums.size();
        for(int i=1; i<N; i++) {
            if(nums[i]<0) swap(mx, mn);
            mx=max(nums[i], mx*nums[i]);
            mn=min(nums[i], mn*nums[i]);
            res=max(mx, res);
        }
        return res;
    }
};