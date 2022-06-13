class Solution {
    int helper(vector<int>& nums) {
        int N = nums.size();
        if(N==1) return nums[0];
        int prev1 = nums[0], prev2 = 0, curr;
        for(int i=1; i<N; i++) {
            curr = max(nums[i]+prev2, prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> tempA(nums.begin()+1, nums.end());
        vector<int> tempB(nums.begin(), nums.end()-1);
        int A = helper(tempA);
        int B = helper(tempB);
        return max(A, B);
    }
};