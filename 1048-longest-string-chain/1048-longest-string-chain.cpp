class Solution {
    bool compare(string& s, string& p) {
        int S = s.size(), P = p.size();
        if(S!=P+1) return false;
        int i=0, j=0;
        while(i<S) {
            if(s[i]==p[j]) {
                i++; j++;
            }
            else {
                i++;
            }
        }
        if(i==S && j==P) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        vector<int> dp(N, 1);
        sort(words.begin(), words.end(), [](string& a, string& b) {return a.size()<b.size();});
        int mx = 1;
        for(int i=0; i<N; i++) {
            for(int prev = 0; prev<i; prev++) {
                if(compare(words[i], words[prev]) && dp[i]<1+dp[prev])
                    dp[i] = 1+dp[prev];
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};