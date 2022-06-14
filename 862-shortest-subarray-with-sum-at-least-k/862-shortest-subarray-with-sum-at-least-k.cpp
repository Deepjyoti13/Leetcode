class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res=INT_MAX, N=nums.size();
        long long sum=0;
        deque<pair<int, long long>> dq;
        for(int i=0; i<N; i++) {
            sum+=nums[i];
            if(sum>=k) res=min(res, i+1);
            
            while(!dq.empty() && sum-dq.front().second>=k) {
                res=min(res,dq.back().first-dq.front().first+1);
                dq.pop_front();
            }
            while(!dq.empty() && sum<dq.back().second)
                dq.pop_back();
            dq.push_back({i, sum});
        }
        return res==INT_MAX?-1:res;
    }
};
