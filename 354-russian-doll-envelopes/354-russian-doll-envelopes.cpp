class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        // for(int i=0; i<N; i++) cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        int l=1;
        for(int i=1; i<N; i++) {
            if(envelopes[i][1]>dp.back()) {
                dp.push_back(envelopes[i][1]);
                l++;
            }
            else {
                int index = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
                dp[index] = envelopes[i][1];
            }
        }
        return l;
    }
};