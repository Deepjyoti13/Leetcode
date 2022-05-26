class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        k = N-k+1;
        priority_queue<int> maxHeap;
        for(int i=0; i<N; i++) {
            maxHeap.push(nums[i]);
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
        return maxHeap.top();
    }
};
