class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minSt.empty()){
            minSt.push(value);
        }
        else{
            if(minSt.top() >= value) minSt.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(!st.empty()){
            if(!minSt.empty() && st.top() == minSt.top()) minSt.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */