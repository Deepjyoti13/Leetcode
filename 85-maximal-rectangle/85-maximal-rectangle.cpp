class Solution {
    int largestRectangleArea(vector<int>& nums) {
        int N = nums.size(), res=0;
        if(N==1) return nums[0];
        stack<pair<int, int>> stkL, stkR;
        vector<int> NSL(N, 0), NSR(N, 0);
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
        for(int i=0; i<N; i++) {
            int sum = nums[i]*(NSR[i]-NSL[i]-1);
            res = max(res, max(nums[i], sum));
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> grid(M, vector<int>(N, 0));
        for(int i=0; i<N; i++) grid[0][i] = matrix[0][i]-'0';
        for(int i=1; i<M; i++)
            for(int j=0; j<N; j++)
                if(matrix[i][j]=='1')
                    grid[i][j]=1+grid[i-1][j];

        int res = 0;
        for(vector<int> v: grid) {
            int area = largestRectangleArea(v);
            res = max(res, area);
        }
        return res;
    }
};