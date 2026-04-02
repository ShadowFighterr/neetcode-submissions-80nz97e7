class MinStack {
private:
    stack<int> st, st1;    
public:
    MinStack() {
        
    }

    void push(int val) {
        st.push(val);
        val = min(val, st1.empty() ? val : st1.top());
        st1.push(val);
    }

    void pop() {
        st.pop();
        st1.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st1.top();}
};