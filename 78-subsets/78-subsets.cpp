class Solution {
    vector<vector<int>> helper(vector<int>& nums, vector<vector<int>> res) {
        int N = nums.size();
        if(N==0) {
            return {{}};
        }
        int curr = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> fromRest = helper(nums, res);
        for(int i=0; i<fromRest.size(); i++) {
            res.push_back(fromRest[i]);
            fromRest[i].push_back(curr);
            res.push_back(fromRest[i]);
        }
        return res;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        return helper(nums, res);
    }
};