#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(int i=0; i<=s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parentheses.push(s[i]);
            }
            else if(s[i] == ')') {
                if(parentheses.empty() || parentheses.top()!='(') {
                    return false;
                }
                parentheses.pop();
            }
            else if(s[i] == ']') {
                if(parentheses.empty() || parentheses.top()!='[') {
                    return false;
                }
                parentheses.pop();
            }
            else if(s[i] == '}') {
                if(parentheses.empty() || parentheses.top()!='{') {
                    return false;
                }
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};