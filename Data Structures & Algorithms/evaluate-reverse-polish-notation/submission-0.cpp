class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens)
        {
            if(s == "+" || s == "*" || s == "-" || s == "/")
            {
                int x, y;
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                if(s == "+") st.push(x+y);
                if(s == "*") st.push(x*y);
                if(s == "-") st.push(y-x);
                if(s == "/") st.push(y/x);
            }
            else
            {
                int x = stoi(s);
                st.push(x);
            }
        }
        return st.top();
    }
};
