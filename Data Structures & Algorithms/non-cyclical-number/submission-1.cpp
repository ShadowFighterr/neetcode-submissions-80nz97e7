class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;
        while(n != 1){
            mp[n] = true;
            // cout << n << ' ';
            int cnt = 0;
            while(n > 0){
                int x = n%10;
                cnt+=(x*x);
                n/=10;
            }
            n = cnt;
            if(mp[n]) {cout << n; return false;}
        }
        return true;
    }
};
// 82
// 70
// 49
// 97
// 130
// 10
// 1