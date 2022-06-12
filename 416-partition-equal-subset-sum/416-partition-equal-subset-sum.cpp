class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), sum=0;
        if(N==1) return false;
        for(int i: nums) sum+=i;
        if(sum%2)
            return false;
        sum/=2;
        bool** t = new bool*[N+1];
        for(int i=0; i<=N; i++) {
            t[i] = new bool[sum+1];
            for(int j=0; j<=sum; j++)
                t[i][j] = false;
        }
        t[0][0] = true;
        for(int i = 1; i < N + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(nums[i - 1] <= j)
                    t[i][j] = t[i-1][j] || t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[N][sum];
    }
};