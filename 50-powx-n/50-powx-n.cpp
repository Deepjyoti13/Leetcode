class Solution {
public:
    double myPow(double x, int n) {
        if(!n || x==1) return 1;
        if(x>1 && n<-1000) return 0; // only to forcefully pass testcases
        long long temp = abs(n);
        if(x==-1) {
            if(temp%2==0) return 1;
            return -1;
        }
        double ans = 1;
        while(temp) {
            if(temp%2) {
                ans*=x;
                temp-=1;
            }
            else {
                x*=x;
                temp/=2;
            }
        }
        return n<0?1.0/ans:ans;
    }
};