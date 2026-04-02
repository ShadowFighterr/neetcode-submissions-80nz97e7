class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            unsigned carry = (unsigned)(a & b) << 1;
            a^=b;
            b = carry;
        }
        return a;
    }
};
