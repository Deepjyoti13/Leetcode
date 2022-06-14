class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int N = nums.size(), res=0;
        if(N==1) return nums[0];
        stack<pair<int, int>> stk;
        vector<int> NSL(N, 0), NSR(N, 0);
        // NSR
        for(int i=N-1; i>=0; i--) {
            while(!stk.empty() && stk.top().first>=nums[i])
                stk.pop();
            stk.empty()?NSR[i]=N:NSR[i]=stk.top().second;
            stk.push({nums[i], i});
        }
        stk = {};
        // NSL
        for(int i=0; i<N; i++) {
            while(!stk.empty() && stk.top().first>=nums[i])
                stk.pop();
            stk.empty()?NSL[i]=-1:NSL[i]=stk.top().second;
            stk.push({nums[i], i});
        }
        // calculation
        for(int i=0; i<N; i++) {
            int sum = nums[i]*(NSR[i]-NSL[i]-1);
            res = max(res, max(nums[i], sum));
        }
        return res;
    }
};