class Solution {
public:
    int countDigitOne(int n) {
        long long c=-1, temp=n, sum=0, exp, t;
        while(n) {
            c++;
            t=n%10;
            n=n/10;
            if(t==0) continue;
            else {
                exp = pow(10, c);
                if(t==1)
                    sum=sum+temp%exp+1+t*c*exp/10;
                else
                    sum=sum+exp+t*c*exp/10;
                // cout<<t<<" "<<x<<" "<<y<<" "<<c<<" "<<sum<<endl;
            }
        }
        return sum;
    }
};

