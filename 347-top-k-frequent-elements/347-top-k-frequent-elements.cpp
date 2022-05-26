class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(int i=0; i<nums.size(); i++)
            seen[nums[i]]++;
        
        vector<int> res;
        
        priority_queue<pair<int,int>> maxHeap;
        
        for(auto i=seen.begin(); i!=seen.end(); i++) {
            maxHeap.push(make_pair(i->second, i->first));
            if(maxHeap.size()>seen.size()-k) {
                res.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        
        return res;
    }
};