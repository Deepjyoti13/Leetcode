class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> braces;
        stack<int> index;
        index.push(-1);
        int result=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(')
            {
                index.push(i);
                braces.push('(');
            }
            else {
                if(!braces.empty() && braces.top() == '(') {
                    index.pop();
                    braces.pop();
                    result = max(result, i-index.top());
                }
                else {
                    index.push(i);
                }
            }
        }
        return result;
    }
};