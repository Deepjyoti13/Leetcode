class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> answer;
        for(int i=0; i<nums.size(); i++) {
            int needed_num = target - nums[i];
            if(cache.find(needed_num) == cache.end())
                cache[nums[i]]=i;
            else {
                answer.push_back(i);
                answer.push_back(cache[needed_num]);
                return answer;
            }
            
        }
        return answer;
    }
};