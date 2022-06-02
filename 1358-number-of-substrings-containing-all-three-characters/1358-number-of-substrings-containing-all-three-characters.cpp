class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> counter(3, 0);
        int l=0, r=0, res=0, N = s.length();
        while(r<N) {
            counter[s[r++]-'a']++;
            while(counter[0] && counter[1] && counter[2]) {
                counter[s[l++]-'a']--;
            }
            res+=l;
        }
        return res;
    }
};