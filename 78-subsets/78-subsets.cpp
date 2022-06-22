class Solution {
    void helper(vector<int>& nums, int ind, int N, vector<int>& ds, vector<vector<int>>& res) {
        if(ind==N) {
            res.push_back(ds);
            return;
        }
        if(ind>N) return;
        ds.push_back(nums[ind]);
        helper(nums, ind+1, N, ds, res);
        ds.pop_back();
        helper(nums, ind+1, N, ds, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int N = nums.size();
        helper(nums, 0, N, ds, res);
        return res;
    }
};