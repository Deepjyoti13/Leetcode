class Solution {
    void helper(int index, vector<int> nums, vector<vector<int>>& res, int N) {
        if(index==N-1) {
            res.push_back(nums);
            return;
        }
        for(int i=index; i<N; i++) {
            if(i==index || nums[index]!=nums[i]) {
                swap(nums[i], nums[index]);
                helper(index+1, nums, res, N);
            }
        }
    }
public:

vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size==0) return res;
        sort(nums.begin(), nums.end());
        helper(0, nums, res, size);
        return res;
    }
};