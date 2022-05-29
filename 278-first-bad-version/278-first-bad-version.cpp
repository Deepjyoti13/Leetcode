// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1 && isBadVersion(1)) return 1;
        int low=1, high=n;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(isBadVersion(mid)) {
                if(!isBadVersion(mid-1)) return mid;
                high=mid;
            }
            else {
                low=mid+1;
            }
        }
        return -1;
    }
};