class Solution {
    int merge(vector<int>& nums, int low, int mid, int high) {
        int j=mid+1, res=0;
        for(int i=low; i<=mid; i++) {
            while(j<=high && nums[i]>2LL*nums[j])
                j++;
            res+=(j-(mid+1));
        }
        vector<int> temp;
        int left=low, right=mid+1;
        while(left<=mid && right<=high) {
            if(nums[left]<=nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid)
            temp.push_back(nums[left++]);
        while(right<=high)
            temp.push_back(nums[right++]);
        for(int i=low; i<=high; i++)
            nums[i]=temp[i-low];
        return res;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        if(low>=high) return 0;
        int mid = (high+low)/2;
        int res = mergeSort(nums, low, mid);
        res+=mergeSort(nums, mid+1, high);
        res+=merge(nums, low, mid, high);
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};