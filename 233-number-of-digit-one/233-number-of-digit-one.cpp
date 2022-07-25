class Solution {
public:
    int countDigitOne(int n) {
        long long c=-1, temp=n, sum=0;
        while(n) {
            c++;
            long long t=n%10;
            n=n/10;
            if(t==0) continue;
            else {
                long long exp = pow(10, c);
                long long x=t*c*exp/10;
                long long y=0;
                if(t==1) {
                    y=temp%exp+1;
                }
                else y=exp;
                sum=sum+x+y;
                // cout<<t<<" "<<y<<" "<<x<<" "<<c<<" "<<sum<<endl;
            }
        }
        return sum;
    }
};

