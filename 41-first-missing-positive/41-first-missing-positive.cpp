class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int Size = nums.size();
        for(int i=0; i<Size; i++) {
            if(nums[i]<=0) nums[i]=nums.size()+2;
        }
        for(int i=0; i<Size; i++) {
            int t = abs(nums[i]);
            if(t<=Size && nums[t-1]>0) {
                nums[t-1] *= -1;
            }
        }
        for(int i=0; i<Size; i++) {
            if(nums[i]>=0)
                return i+1;
        }
        return Size+1;
        }
    };

// 1 2 0
// 0 1 2
// i=0 nums[0]=1 max=1 nums[0]=-1
// i=1 nums[1]=2 max=2 nums[1]=-2
// i=2 nums[2]=0 max=2 nums[]