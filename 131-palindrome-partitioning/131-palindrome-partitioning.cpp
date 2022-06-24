class Solution {
    bool isPalindrome(string& s, int low, int high) {
        while(low<=high) {
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
    void helper(string& s, int ind, int N, vector<string>& ds, vector<vector<string>>& res) {
        if(ind==N) {
            res.push_back(ds);
            return;
        }
        for(int i=ind; i<N; i++) {
            if(isPalindrome(s, ind, i)) {
                string str = s.substr(ind, i-ind+1);
                ds.push_back(str);
                helper(s, i+1, N, ds, res);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        int N = s.size();
        helper(s, 0, N, ds, res);
        return res;
    }
};