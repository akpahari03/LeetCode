class MinStack {
public:
    stack<long long> s;
    long long mini;
    MinStack() {
    }
    
    void push(int val) {
        long long value=val;
        //for first element
        if(s.empty()) {
            s.push(value);
            mini=value;
        }
        else {
            if(val<mini) {
                s.push(2*value-mini);
                mini=value;
            }
            else {
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long curr=s.top();
        s.pop();
        if(curr<mini) {
            mini=2*mini-curr;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        long long curr=s.top();
        if(curr<mini) return mini;
        else return curr;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mini;
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