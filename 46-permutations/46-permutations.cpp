class Solution {
    void helper(int index, vector<int>& nums, vector<vector<int>>& res, int N) {
        if(index==N) {
            res.push_back(nums);
            return;
        }
        for(int i=index; i<N; i++) {
            swap(nums[i], nums[index]);
            helper(index+1, nums, res, N);
            swap(nums[i], nums[index]);
        }
    }
public:

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size==0) return res;
        helper(0, nums, res, size);
        return res;
    }
};