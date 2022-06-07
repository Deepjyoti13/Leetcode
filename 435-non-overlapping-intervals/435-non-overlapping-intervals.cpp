class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b) {return a[1]<b[1];});
        int ending = INT_MIN, count=0;
        for(vector<int> v: intervals) {
            if(ending <= v[0]) ending = v[1];
            else {
                ending = min(ending, v[1]);
                count++;
            }
        }
        return count;
    }
};

