class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();
        if(N<2) return N;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        vector<int> dp(N, 0);
        dp[0] = 1;
        for(int i=1; i<N; i++) {
            int inc = 1;
            int low = 0, high = i-1, last = -1;
            while(low<=high) {
                int mid = low+(high-low)/2;
                if(pairs[mid][1]<pairs[i][0]) {
                    last = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            if(last!=-1) inc+=dp[last];
            int exc = dp[i-1];
            dp[i] = max(inc, exc);
        }
        return dp[N-1];
    }
};