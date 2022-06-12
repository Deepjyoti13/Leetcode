class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(N, 1);
        vector<int> hash(N, 0);
        int res=0, lastIndex=0;
        for(int i=0; i<N; i++) hash[i]=i;
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j]==0)
                    if(dp[i]<1+dp[j]) {
                        dp[i]=1+dp[j];
                        hash[i] = j;
                    }
                if(res<dp[i]) {
                    res = dp[i];
                    lastIndex = i;
                }
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};