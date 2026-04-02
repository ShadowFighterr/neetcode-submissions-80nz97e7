class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*') star.push(i);
            else if(s[i] == '(') left.push(i);
            else{
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        cout << left.size() << ' ';
        while(!left.empty() && !star.empty()){
            if(left.top() > star.top()) return false;
            left.pop(), star.pop();
        }
        cout << left.size();
        return left.empty();
    }
};
