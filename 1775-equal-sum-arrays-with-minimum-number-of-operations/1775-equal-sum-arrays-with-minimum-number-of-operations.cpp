class Solution {
    int helper(vector<int>& nums1, vector<int>& nums2, int N1, int N2, int s1, int s2) {
        int ops=0;
        
        if(N1>N2*6) return -1;
        int p1=N1-1;
        int p2=0;
        while(p1>=0 || p2<N2) {
            if(s1<=s2) break;
            int change1 = p1>=0?nums1[p1]-1:-1;
            int change2 = p2<N2?6-nums2[p2]:-1;
            if(change1 > change2) {
                s1=s1-nums1[p1]+1; 
                p1--;
            } 
            else {
                s2=s2-nums2[p2]+6;
                p2++;
            }
            ops++;
        }
        
        return ops;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size(), N2=nums2.size(), s1=0, s2=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i: nums1) s1+=i;
        for(int i: nums2) s2+=i;
        if(s1>s2) return helper(nums1, nums2, N1, N2, s1, s2);
        return helper(nums2, nums1, N2, N1, s2, s1);
    }
};