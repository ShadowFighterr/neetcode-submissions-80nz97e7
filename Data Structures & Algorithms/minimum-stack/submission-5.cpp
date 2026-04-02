class MinStack {
    public:
    stack<int> st;
    set<int> s;
    unordered_map<int, int> mp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val), mp[val]++;
        s.insert(val);
    }
    
    void pop() {
        if(mp[st.top()]-1 == 0) s.erase(st.top());
        else {if(mp[st.top()]-1 > 0) mp[st.top()]--;}
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *s.begin();
    }
};
