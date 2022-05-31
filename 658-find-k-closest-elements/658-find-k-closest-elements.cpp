class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i: arr) {
            maxHeap.push(make_pair(abs(i-x), i));
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<int> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};