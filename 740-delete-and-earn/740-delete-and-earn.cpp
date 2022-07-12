class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> bucket;
        for (int num : nums)
            bucket[num] += num;
        int prev1 = 0, prev2 = 0;
        for(auto i: bucket) {
            if(bucket.find(i.first-1)==bucket.end()) {
                prev2=prev1;
                prev1+=i.second;
            }
            else {
                int curr = max(i.second+prev2, prev1);
                prev2=prev1;
                prev1=curr;    
            }
        }
        return prev1;
    }
};