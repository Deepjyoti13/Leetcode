class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> stk;
        vector<int> res;
        
        for(int i=2*N-1; i>=0; i--) {
            while(!stk.empty() && stk.top()<=nums[i%N]) {
                stk.pop();
            }
            if(i<N) {
                if(!stk.empty()) res.push_back(stk.top());
                else res.push_back(-1);
            }
            // if(stk.empty()) {
                stk.push(nums[i%N]);
            // }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};