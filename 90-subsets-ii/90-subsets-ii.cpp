class Solution {
    void helper(vector<int>& nums, int ind, int N, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for(int i=ind; i!=nums.size(); i++) {
            if(i==ind || nums[i-1]!=nums[i]) {
                curr.push_back(nums[i]);
                helper(nums, i+1, N, curr, res);
                curr.pop_back();   
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(nums, 0, nums.size(), curr, res);
        return res;
    }
};