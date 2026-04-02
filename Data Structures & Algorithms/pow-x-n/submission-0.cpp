class Solution {
public:
    // const long double MOD = 1e9+7;
    double myPow(double x, int n) {
        long double res = 1;
        if(n < 0){
            x = 1 / x;
            n*=-1;
        }
        while(n){
            if(n&1) res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
};
