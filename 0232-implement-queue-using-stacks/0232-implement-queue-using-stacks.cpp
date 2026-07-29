class MyQueue {
public:
    stack<int> first;
    stack<int> second;
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        int v;
        while(!first.empty()){
            int val = first.top();
            first.pop();
            if(first.empty()) {
                v = val;
            }
            else second.push(val);
        }
        while(!second.empty()){
            int val = second.top();
            second.pop();
            first.push(val);
        }
        return v;
    }
    
    int peek() {
        int v;
        while(!first.empty()){
            int val = first.top();
            second.push(val);
            first.pop();
            if(first.empty()) {
                v = val;
            }
        }
        while(!second.empty()){
            int val = second.top();
            second.pop();
            first.push(val);
        }
        return v;
    }
    
    bool empty() {
        return (first.empty() && second.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */