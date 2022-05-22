class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapS, mapT;
        for(int i=0; i<t.length(); i++)
            mapT[t[i]]++;
        int start=0, end=0, ans=INT_MAX;
        int count=0;
        int right=0, left=0;
        while(right<=s.length()) {
            if(count<t.length()) {
                if(mapS[s[right]]<mapT[s[right]])
                    count++;
                mapS[s[right]]++;
                right++;
            }
            else if(count==t.length()) {
                if(right-left+1<ans) {
                    ans = right-left+1;
                    start=left;
                    end=right;
                }
                if(--mapS[s[left]]<mapT[s[left]])
                    count--;
                left++;
            }
        }
        string res="";
        for(int i=start; i<end; i++) {
            res+=s[i];
        }
        return res;
    }
};