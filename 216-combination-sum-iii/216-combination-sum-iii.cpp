class Solution {
    void helper(int k, int target, int N, vector<int>& nums, vector<vector<int>>& res, vector<int>& ds) {
        if(k==0 && target==0) res.push_back(ds);
        if(k<=0 || N<=0) return;
        int curr = nums[N-1];
        if(curr<=target) {
            ds.push_back(curr);
            helper(k-1, target-curr, N-1, nums, res, ds);
            ds.pop_back();
        }
        helper(k, target, N-1, nums, res, ds);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>9*k-1) return vector<vector<int>>();
        vector<vector<int>> res;
        vector<int> ds;
        vector<int> nums;
        for(int i=1; i<=9; i++) nums.push_back(i);
        helper(k, n, 9, nums, res, ds);
        return res;
    }
};