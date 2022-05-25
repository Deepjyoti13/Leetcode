class Solution {
    int helper(string s, int N) {
        int ind=-1;
        for(ind=N-2; ind>=0; ind--) {
            if(s[ind]<s[ind+1]) {
                break;
            }
        }
        if(ind<0) return -1;
        int i;
        for(i=N-1; i>=0; i--) {
            if(s[i]>s[ind]) {
                break;
            }
        }
        swap(s[i], s[ind]);
        reverse(s.begin()+ind+1, s.end());
        long long res = stoll(s);
        return res>INT_MAX?-1:res;
    }
public:
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        int N = temp.length();
        int res = helper(temp, N);
        return res;
    }
};
