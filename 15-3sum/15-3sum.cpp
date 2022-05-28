class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0; i<n-2; i++) {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) {
                int low = i+1, high = n-1, target = -1*nums[i];
                while(low<high) {
                    if(nums[low]+nums[high]+nums[i]==0) {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[low]);
                        ans.push_back(nums[high]);
                        res.push_back(ans);
                        while(low<high && nums[low]==nums[low+1]) low = low+1;
                        while(low<high && nums[high]==nums[high-1]) high = high-1;
                        low++; high--;
                    }
                    else if(nums[low]+nums[high]+nums[i]>0) high--;
                    else low++;
                }
            }
        }
        return res;
    }
};