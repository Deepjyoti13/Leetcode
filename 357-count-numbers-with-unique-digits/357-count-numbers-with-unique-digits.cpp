class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;
        if(n>9) n=10;
        int res = 10, multi=9;
        for(int i=1; i<n; i++) {
            multi=multi*(10-i);
            res+=multi;
        }
        return res;
    }
};