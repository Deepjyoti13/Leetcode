class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size==0) return 0;
        unordered_map<char, int> seen;
        int res=0, temp=0, start=0;
        for(int i=0; i<size; i++) {
            if(seen.count(s[i])==0) {
                seen[s[i]] = i;
                temp++;
            }
            else {
                    if(seen[s[i]]>start) {
                    start = seen[s[i]];
                }
                temp = i-start;
                seen[s[i]] = i;
            }
            res = max(temp, res);
        }
        return res;
    }
};