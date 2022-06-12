class Solution {
    int dp[1001][1001];
    int helper(vector<int>& cuts, int n, int i, int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=i; k<=j; k++) {
            res = min(res, helper(cuts, n, i, k-1)+helper(cuts, n, k+1, j)+cuts[j+1]-cuts[i-1]);
        }
        return dp[i][j]=res;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(1);
        cuts.push_back(n);
        int N = cuts.size();
        for(int i=N-2; i>0; i--) cuts[i]=cuts[i-1];
        cuts[0]=0;
        memset(dp, -1, sizeof(dp));
        return helper(cuts, n, 1, N-2);
    }
};

