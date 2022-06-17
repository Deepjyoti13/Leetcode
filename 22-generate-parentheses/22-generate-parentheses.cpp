class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1, vector<string>());
        string t = "";
        vector<string> t2;
        t2.push_back(t);
        dp[0] = t2;
        for(int i = 1; i<=n; i++) {
            int inside = i-1;
            int outside = 0;
            while(inside>=0) {
                for(string in: dp[inside]) {
                    for(string out: dp[outside]) {
                        string temp = "(" + in + ")" + out;
                        dp[i].push_back(temp);
                    }
                }
                inside--;
                outside++;
            }
        }
        return dp[n];
    }
};