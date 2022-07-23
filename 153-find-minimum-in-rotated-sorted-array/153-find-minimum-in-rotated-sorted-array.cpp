class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        if(!N) return -1;
        if(N==1) return nums[0];
        if(N==2) return min(nums[0], nums[1]);
        int low = 0, high = N-1;
        if(nums[low]<nums[high]) return nums[low];
        if(nums[high]<nums[high-1]) return nums[high];
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid-1]>nums[mid]) return nums[mid];
            if(nums[low]<=nums[mid]) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return -1;
    }
};