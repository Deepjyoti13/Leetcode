class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int N = nums.size(), res=0;
        if(N==1) return nums[0];
        stack<pair<int, int>> stkL, stkR;
        vector<int> NSL(N, 0), NSR(N, 0);
        
        // NSL && NSR
        for(int i=0; i<N; i++) {
            while(!stkL.empty() && stkL.top().first>=nums[i])
                stkL.pop();
            stkL.empty()?NSL[i]=-1:NSL[i]=stkL.top().second;
            stkL.push({nums[i], i});
            int j = N-i-1;
            while(!stkR.empty() && stkR.top().first>=nums[j])
                stkR.pop();
            stkR.empty()?NSR[j]=N:NSR[j]=stkR.top().second;
            stkR.push({nums[j], j});
            
        }
        // calculation
        for(int i=0; i<N; i++) {
            int sum = nums[i]*(NSR[i]-NSL[i]-1);
            res = max(res, max(nums[i], sum));
        }
        return res;
    }
};