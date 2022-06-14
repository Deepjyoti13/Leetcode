class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> stk;
        vector<int> res(N, 0);
        
        for(int i=2*N-1; i>=0; i--) {
            while(!stk.empty() && stk.top()<=nums[i%N]) {
                stk.pop();
            }
            if(i<N) {
                if(!stk.empty()) res[i] = stk.top();
                else res[i] = -1;
            }
            stk.push(nums[i%N]);
        }
        // reverse(res.begin(), res.end());
        
        return res;
    }
};