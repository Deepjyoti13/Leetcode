class Solution {
    bool canPartitionKSubsets(vector<int>& nums, int target, int k, int sum, int i, vector<bool>& visited, int N) {
        if(k==1) return true;
        if(i>=N) return false;
        if(sum==target) return canPartitionKSubsets(nums, target, k-1, 0, 0, visited, N);
        for(int j=i; j<N; j++) {
            if(visited[j] || sum+nums[j]>target) continue;
            visited[j] = true;
            if(canPartitionKSubsets(nums, target, k, sum+nums[j], j+1, visited, N)) return true;
            visited[j]=false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        vector<bool> visited(N, false);
        if(k>N || sum%k) return false;
        return canPartitionKSubsets(nums, sum/k, k, 0, 0, visited, N);
    }
};