class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<vector<int>> hash(N);
        for(int i=0; i<N; i++) {
            hash[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(hash.begin(), hash.end(), [](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        vector<int> dp(N, 0);
        dp[0] = hash[0][2];
        for(int i=1; i<N; i++) {
            int inc = hash[i][2];
            int last = -1;
            int low = 0, high = i-1;
            while(low<=high) {
                int mid = low+(high-low)/2;
                if(hash[mid][1]<=hash[i][0]) {
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