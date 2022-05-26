class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<N; i++) {
            minHeap.push(nums[i]);
            if(minHeap.size()>k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
