class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size(), low = 0, high = N-1;
        if(nums[0]>=target) return 0;
        if(nums[N-1]<target) return N;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) {
                if(nums[mid-1]<target && target<nums[mid]) return mid;
                high = mid-1;
            }
            else {
                if(nums[mid]<target && target<nums[mid+1]) return mid+1;
                low = mid+1;
            }
        }
        return 0;
    }
};