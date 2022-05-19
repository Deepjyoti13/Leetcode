class MinStack {
    stack<long long> stk;
    long long minimum;
public:
    MinStack() {
        while(!stk.empty()) stk.pop();
        minimum = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(stk.empty()) {
            stk.push(val);
            minimum = val;
        }
        else {
            if(val<minimum) {
                stk.push(2*val*1LL-minimum);
                minimum = val;
            }
            else {
                stk.push(val);
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long long val = (long long) stk.top();
        stk.pop();
        if(val<minimum) {
            minimum = 2*minimum*1LL-val;
        }
    }
    
    int top() {
        if(stk.empty()) return -1;
        long long val = stk.top();
        if(val<minimum) return minimum;
        return val;
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */