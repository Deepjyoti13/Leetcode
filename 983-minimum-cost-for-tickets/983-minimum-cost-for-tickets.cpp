class Solution {
    bool isValid(int target, vector<int>& days, int N) {
        int low = 0, high = N-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(days[mid]==target) return true;
            else if(days[mid]<target) low = mid+1;
            else high = mid-1;
        }
        // for(int i=0; i<days.size(); i++) if(days[i]==target) return true;
        return false;
    }
    int helper(int curr, vector<int>& days, vector<int>& costs, vector<int>& dp, int N) {
        if(curr>days[N-1]) return dp[curr] = 0;
        if(dp[curr]) return dp[curr];
        int ans=INT_MAX;
        if(isValid(curr, days, N)) {
            ans = helper(curr+1, days, costs, dp, N) + costs[0];
            ans = min(ans, helper(curr+7, days, costs, dp, N) + costs[1]);
            ans = min(ans, helper(curr+30, days, costs, dp, N) + costs[2]);
        }
        else {
            return dp[curr] = helper(curr+1, days, costs, dp, N);
        }
        return dp[curr] = ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> dp(days[N-1]+31, 0);
        return helper(days[0], days, costs, dp, N);
    }
};