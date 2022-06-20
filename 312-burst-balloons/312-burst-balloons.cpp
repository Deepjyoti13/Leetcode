class Solution {
    int dp[301][301];
    int helper(vector<int>& nums, int i, int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx = 0;
        for(int k = i; k<=j; k++) {
            mx = max(mx, helper(nums, i, k-1)+helper(nums, k+1, j)+nums[i-1]*nums[k]*nums[j+1]);
        }
        return dp[i][j] = mx;
    }
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return helper(nums, 1, N);
    }
};





