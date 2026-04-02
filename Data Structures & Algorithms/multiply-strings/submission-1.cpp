class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string res = "";
        vector<int> digits(10000, 0), ans;
        int idx = 0; 
        for(char c1 : num2){
            int x = c1 - '0';
            int i = idx;
            for(char c2 : num1){
                int y = c2 - '0';
                digits[i] += (x*y);
                ++i;
            }
            ++idx;
        }
        int tmp = 0;
        // cout << digits[idx+num1.size()-1] << ' ';
        for(int i = idx+num1.size()-2; i >= 0; i--) {
            int x = digits[i]+tmp;
            ans.push_back(x%10);
            tmp = x/10;
        }
        if(tmp != 0) {
            int a, b;
            a = tmp%10, b = tmp/100;
            if(a != 0)ans.push_back(a);
            if(b != 0) ans.push_back(b);
        }
        for(int i = ans.size()-1; i >= 0; i--) res+=to_string(ans[i]);
        return res;
    }
};
