class Solution {
    void helper(int i, int l, vector<int>& candidates, vector<vector<int>>& res, vector<int>& ds, int target) {
        int size = candidates.size();
        if(i==size && target==0) res.push_back(ds);
        if(i==size) return;
        int curr = candidates[i];
        if(curr<=target && (l==-1 || candidates[i]!=candidates[l])) {
            ds.push_back(curr);
            helper(i+1, l, candidates, res, ds, target-curr);
            ds.pop_back();
        }
        helper(i+1, i, candidates, res, ds, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, -1, candidates, res, ds, target);
        return res;
    }
};