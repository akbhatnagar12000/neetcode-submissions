class MinStack {
    stack<int> s1, s2;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        // push into min stack if it's <= current min
        if (s1.empty() || val <= s1.top()) {
            s1.push(val);
        }

        s2.push(val);
    }
    
    void pop() {
        if (s2.empty()) return;

        if (s2.top() == s1.top()) {
            s1.pop();
        }

        s2.pop();
    }
    
    int top() {
        return s2.top();
    }
    
    int getMin() {
        return s1.top();
    }
};