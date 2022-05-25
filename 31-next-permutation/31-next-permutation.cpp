class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N=nums.size();
        int ind1, ind2=0;
        for(ind1=N-2; ind1>=0; ind1--) {
            if(nums[ind1+1]>nums[ind1]) {
                break;
            }
        }
        if(ind1<0) reverse(nums.begin(), nums.end());
        else {
            for(int i=N-1; i>ind1; i--) {
                if(nums[i]>nums[ind1]) {
                    ind2=i;
                    break;
                }
            }
            swap(nums[ind1], nums[ind2]);
            reverse(nums.begin()+ind1+1, nums.end());
        }
    }
};