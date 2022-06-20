class Solution {
    int helper(vector<int>& arr, int i, int p, int N, vector<int>& dp) {
        if(i==N) return 0;
        if(dp[i]) return dp[i];
        int mx=INT_MIN, res=INT_MIN, len=0;
        for(int k=i; k<min(N, i+p); k++) {
            mx = max(mx, arr[k]);
            len++;
            int sum = len*mx + helper(arr, k+1, p, N, dp);
            res = max(sum, res);
        }
        return dp[i] = res;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), 0);
        return helper(arr, 0, k, arr.size(), dp);
    }
};