class Solution {
    void helper(int i, vector<int>& candidates, vector<vector<int>>& res, vector<int>& ds, int target) {
        int size = candidates.size();
        if(i==size && target==0) res.push_back(ds);
        if(i==size) return;
        int curr = candidates[i];
        if(curr<=target) {
            ds.push_back(curr);
            helper(i, candidates, res, ds, target-curr);
            ds.pop_back();
        }
        helper(i+1, candidates, res, ds, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, candidates, res, ds, target);
        return res;
    }
};