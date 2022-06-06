class Solution {
    vector<vector<int>> dp;
    int helper(vector<int>& coins, int target, int N) {
        if(target==0) return 1;
        if(N==0) return 0;
        if(dp[N][target]!=-1) return dp[N][target];
        if(coins[N-1]>target) {
            return dp[N][target] = helper(coins, target, N-1);
        }
        return dp[N][target] = helper(coins, target-coins[N-1], N) + helper(coins, target, N-1);
    }
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        dp.resize(N+1,vector<int>(amount+1,-1));
        return helper(coins, amount, N);
    }
};