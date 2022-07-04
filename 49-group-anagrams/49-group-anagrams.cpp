class Solution {
    string sortStr(string str) {
        vector<int> letter(26);
        for(char ch: str) {
            letter[ch-'a']++;
        }
        int i=0;
        string res="";
        while(i<26) {
            if(!letter[i]) i++;
            else {
                res+=i+'a';
                letter[i]--;
            }
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        
        for(string& str: strs) {
            seen[sortStr(str)].push_back(str);
        }
        
        vector<vector<string>> res;
        for(auto& i: seen) {
            res.push_back(i.second);
        }
        return res;
    }
};