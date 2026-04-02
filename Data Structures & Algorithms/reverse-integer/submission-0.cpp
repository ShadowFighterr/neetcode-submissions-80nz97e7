class Solution {
public:
    int reverse(int x) {
        int mn, mx;
        mn = INT_MIN;
        mx = INT_MAX;
        cout << mx ;
        int res = 0;
        while(x != 0){
            int tmp = x%10;
            if(res > mx / 10 || (res == mx / 10 && tmp > mx%10)) return 0;
            if(res < mn / 10 || (res == mn / 10 && tmp < mn%10)) return 0;
            res = (res*10)+tmp;
            x/=10;
        }
        return res;
    }
};
