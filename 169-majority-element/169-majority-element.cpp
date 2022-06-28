class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, candidate=0;
        for(int num: nums) {
            if(!count) candidate = num;
            if(candidate == num) count++;
            else count--;
        }
        return candidate;
    }
};