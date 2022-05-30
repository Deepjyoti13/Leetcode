class Solution {
    bool isValid(vector<int>& piles, int mid, int h) {
        int k=0, sum=0;
        for(int i: piles) {
            k+=i/mid;
            if(i%mid) k++;
            
            if(k>h) return false;   
        }        
        return true;
    }
public:
    int smallestDivisor(vector<int>& piles, int h) {
        int res=0;
        int low = 1, high = 1000000;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(isValid(piles, mid, h)) {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return res;
    }
};
















// 3 4 5 6 7 8 9 10 11

