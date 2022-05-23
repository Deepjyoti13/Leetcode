class Solution {
    int result;
    int helper(vector<int>& nums1, vector<int>& nums2, int m, int n, vector<vector<int>>& dp) {
    if(m==0 || n==0) return 0;
    if(dp[m][n] != -1) return dp[m][n];
    helper(nums1, nums2, m-1, n, dp);
    helper(nums1, nums2, m, n-1, dp);
    if(nums1[m-1]==nums2[n-1]) {
        dp[m][n] = 1+helper(nums1, nums2, m-1, n-1, dp);
    }
    else {
        dp[m][n] = 0;
    }
    result = max(result, dp[m][n]);
    return dp[m][n];
}
 
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size(), N = nums2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, -1));
        helper(nums1, nums2, M, N, dp);
        return result;
    }
};