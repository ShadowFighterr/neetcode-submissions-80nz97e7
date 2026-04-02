class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.insert(digits.begin(), 0);
        int n = digits.size();
        digits[n-1]++;
        for(int i = n-1; i >= 1; i--){
            if(digits[i] == 10) digits[i] = 0, digits[i-1]++;
        }
        if(digits[0] == 0) digits.erase(digits.begin());
        return digits;
    }
};
