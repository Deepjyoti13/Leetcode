class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1=-1e8, nums2=-1e8, count1=0, count2=0, size = nums.size();
        for(int num: nums) {
            if(num==nums1) count1++;
            else if(num==nums2) count2++;
            else if(count1==0) {
                nums1=num;
                count1=1;
            }
            else if(count2==0) {
                nums2=num;
                count2=1;
            }
            else {
                count1--;
                count2--;
            }
        }
        vector<int> res;
        count1=0, count2=0;
        for(int num: nums) {
            if(nums1==num) count1++;
            if(nums2==num) count2++;
        }
        if(count1>size/3) res.push_back(nums1);
        if(count2>size/3) res.push_back(nums2);
        return res;
    }
};