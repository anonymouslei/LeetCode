class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        tmp.push(x);
        exchange();
        res = tmp;
        while(tmp.size())
        {
            tmp.pop();
        }
    }
    
    int pop() {
        int res_value = res.front();
        res.pop();
        return res_value;
    }
    
    int top() {
        return res.front();
    }
    
    bool empty() {
        return res.empty();
    }
private:
    queue<int> res, tmp;
    void exchange() {
        while(res.size())
        {
            tmp.push(res.front());
            res.pop();
        }
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