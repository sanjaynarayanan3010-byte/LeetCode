class MyStack {
public:
    queue<int> first;
    queue<int> second;
    MyStack() {
        
    }
    
    void push(int x) {
        if(!first.empty()) first.push(x);
        else if(!second.empty()) second.push(x);
        else first.push(x);
    }
    
    int pop() {
        int v;
        if(!first.empty()){
            while(!first.empty()){
                int val = first.front();
                first.pop();
                if(first.empty()) {
                    v = val;
                }
                else second.push(val);
            }
        }
        else if(!second.empty()){
            while(!second.empty()){
                int val = second.front();
                second.pop();
                if(second.empty()) {
                    v = val;
                }
                else first.push(val);
            }
        }
        return v;
    }
    
    int top() {
        int v;
        if(!first.empty()){
            while(!first.empty()){
                int val = first.front();
                second.push(val);
                first.pop();
                if(first.empty()) {
                    v = val;
                }
            }
        }
        else if(!second.empty()){
            while(!second.empty()){
                int val = second.front();
                first.push(val);
                second.pop();
                if(second.empty()) {
                    v = val;
                }
            }
        }
        return v;
    }
    
    bool empty() {
        return (first.empty() && second.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */