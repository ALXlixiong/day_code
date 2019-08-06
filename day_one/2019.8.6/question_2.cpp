class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(data_.empty() && min_.empty())
        {
            data_.push(x);
            min_.push(x);
        }
        else
        {
            data_.push(x);
            if(x<min_.top())
                min_.push(x);
            else
                min_.push(min_.top());
        }
    }
    
    void pop() {
        data_.pop();
        min_.pop();
    }
    
    int top() {
        return data_.top();
    }
    
    int getMin() {
        return min_.top();
    }
    stack<int> data_;
    stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
