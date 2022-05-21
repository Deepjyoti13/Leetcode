class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        vector<int> res(2,  -1);
        while(low<high) {
            if(numbers[low]+numbers[high]>target) high--;
            else if(numbers[low]+numbers[high]<target) low++;
            else {
                res[0]=low+1;
                res[1]=high+1;
                break;
            }
        }
        return res;
    }
};