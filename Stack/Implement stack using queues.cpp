class MyStack {
public:
    stack<int> ans;
    MyStack() {
        stack<int> ans;
    }
    
    void push(int x) {
        ans.push(x);
    }
    
    int pop() {
        int a=ans.top();
        ans.pop();
        return a;
    }
    
    int top() {
        int a=ans.top();
        // ans.pop(x)
        return a;
    }
    
    bool empty() {
        return ans.empty();
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