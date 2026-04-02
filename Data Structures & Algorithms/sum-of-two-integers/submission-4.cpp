class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            unsigned carry = (unsigned)(a & b) << 1;
            a^=b;
            b = carry;
            cout << a << ' ' << b << ' ' << carry << '\n'; 
        }
        return a;
    }
};
