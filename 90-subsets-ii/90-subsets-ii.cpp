class Solution {
    void helper(vector<int>& nums, int ind, int prev, int N, vector<int>& ds, vector<vector<int>>& res) {
        if(ind==N) {
            res.push_back(ds);
            return;
        }
        if(ind>N) return;
        // cout<<ind<<" "<<prev<<" "<<N<<endl;
        if(prev==-1 || nums[ind]!=nums[prev]) {
            ds.push_back(nums[ind]);
            helper(nums, ind+1, prev, N, ds, res);
            ds.pop_back();
        }
        helper(nums, ind+1, ind, N, ds, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==1) {
            res.push_back({});
            res.push_back(nums);
            return res;
        }
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(nums, 0, -1, nums.size(), ds, res);
        return res;
    }
};