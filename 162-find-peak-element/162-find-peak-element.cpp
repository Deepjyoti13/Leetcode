class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int N = nums.size();
        if(!N) return -1;
        if(N==1) return 0;
        if(N==2) return nums[0]>nums[1]?0:1;
        int low = 0, high = N-1;
        if(nums[low]>nums[low+1]) return low;
        if(nums[high]>nums[high-1]) return high;
        while(low<=high) {
            int mid = low+(high-low)/2;
            cout<<mid<<endl;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]<=nums[mid+1]) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return -1;
    }
};