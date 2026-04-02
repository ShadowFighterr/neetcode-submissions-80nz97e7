class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char ch : s)
        {
            if(ch == '{' || ch == '[' || ch == '(') a.push(ch);
            else
            {
                // cout << a.top()-ch;
                if(!a.empty() && (abs(a.top()-ch) == 1 || abs(a.top()-ch) == 2)) a.pop();
                else return false;
            }
            // cout << a.top();
        }
        if(a.empty()) return true;
        else return false;
    }
};
