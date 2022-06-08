class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        if(N==1) return nums[0];
        if(N==2) return nums[0]*nums[1]+max(nums[0], nums[1]);
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for(int i=N-1; i>=0; i--) {
            for(int j=i; j<N; j++) {
                for(int k=i; k<=j; k++) {
                    int a=0, b=0, c=nums[k];
                    if(k!=0) a = dp[i][k-1];
                    if(i!=0) c=c*nums[i-1];
                    if(k!=N-1) b = dp[k+1][j];
                    if(j!=N-1) c=c*nums[j+1];
                    dp[i][j] = max(dp[i][j], a + c + b);
                }
            }
        }

        return dp[0][N-1];
    }
};





