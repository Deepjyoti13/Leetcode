class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> bucket(10001);
        for (int num : nums)
            bucket[num] += num;
        int prev1 = 0, prev2 = 0;
        for(int i=0; i<10001; i++) {
            int curr = max(bucket[i]+prev2, prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};