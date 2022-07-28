class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        if(N==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[N-1]!=nums[N-2]) return nums[N-1];
        int low = 0, high = N-1, res=-1;
        while(low<high) {
            int mid=low+(high-low)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                low=mid+1;
            else {
                res = mid;
                high = mid; 
            }
        }
        return nums[res];
    }
};