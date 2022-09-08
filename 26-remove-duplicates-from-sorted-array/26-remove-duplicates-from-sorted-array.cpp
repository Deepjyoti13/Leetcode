class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if(N==1) return 1;
        int l=0, r=1, count=1;
        while(r<N) {
            if(nums[l]==nums[r]) r++;
            else {
                l++;
                nums[l]=nums[r];
                count++;
            }
        }
        return count;
    }
};