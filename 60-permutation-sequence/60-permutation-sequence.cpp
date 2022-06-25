class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1; i<n; i++) {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k--;
        while(true) {
            int ind = k/fact;
            ans+=to_string(nums[ind]);
            nums.erase(nums.begin()+ind);
            if(!nums.size()) break;
            k%=fact;
            fact/=nums.size();
        }
        return ans;
    }
};