class Solution {
    bool isValid(vector<int>& weights, int mid, int days) {
        int day=1, sum=0;
        for(int i: weights) {
            sum+=i;
            if(sum>mid) {
                day++;
                sum=i;
            }
            if(day>days) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN, high=0, res=0;
        for(int i: weights) {
            low = max(low, i);
            high+=i;
        }
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(isValid(weights, mid, days)) {
                res=mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        
        return res;
    }
};