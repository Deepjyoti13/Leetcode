class Solution {
    
    vector<string> mapping;
    vector<string> helper(string num, vector<string> result) {
        if(num.length()==0) {
            vector<string> t;
            t.push_back("");
            return t;
        }
        int front = num[0] - '0';
        string rest = num.substr(1);
        string alphabets = mapping[front];
        vector<string> fromRest = helper(rest, result);
        for(int i=0; i<alphabets.size(); i++) { // d   e    f
            for(int j=0; j<fromRest.size(); j++) { //   a b c
                result.push_back(alphabets[i] + fromRest[j]);
            }
        }
        return result;
    }
    
public:
    
vector<string> letterCombinations(string num) {
        int n = num.size();
        vector<string> res;
        if(n==0) {
            return res;
        }
        mapping = {"", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return helper(num, res);
    }
};