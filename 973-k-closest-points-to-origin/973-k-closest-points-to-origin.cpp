class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> maxHeap;
        for(int i=0; i<points.size(); i++) {
            double x = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            maxHeap.push(make_pair(x, i));
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back(vector<int>{points[maxHeap.top().second][0], points[maxHeap.top().second][1]});
            maxHeap.pop();
        }
        return res;
    }
};