class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        // for(int i=0; i<N; i++) cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        vector<int> nums;
        vector<int> dp;
        for(auto v: envelopes) nums.push_back(v[1]);
        // for(auto& i: nums) cout<<i<<" ";
        dp.push_back(nums[0]);
        int l=1;
        for(int i=1; i<N; i++) {
            if(nums[i]>dp.back()) {
                dp.push_back(nums[i]);
                l++;
            }
            else {
                int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[index] = nums[i];
            }
        }
        return l;
    }
};