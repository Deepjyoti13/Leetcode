class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
        if(nums[abs(nums[i])-1]<0)
            return abs(nums[i]);
        nums[abs(nums[i])-1] *= -1;
    }
    cout<<endl;
    return -99;
    }
};

// i=0 3 1 -3 4 2
// i=1 -3 2 -3 4 2
// i=2 