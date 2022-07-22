class Solution {
    int atMaxKDistinct(vector<int>& nums, int& N, int k) {
        int l=0, r=0, count=0;
        unordered_map<int, int> seen;
        while(r<N) {
            seen[nums[r]]++;
            while(seen.size()>k) {
                seen[nums[l]]--;
                if(!seen[nums[l]]) seen.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int N = nums.size();
        return atMaxKDistinct(nums, N, k) - atMaxKDistinct(nums, N, k-1);
    }
};
