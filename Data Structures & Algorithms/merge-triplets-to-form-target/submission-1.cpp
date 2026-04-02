class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a, b, c;
        a = b = c = -1;
        for(vector<int> &v : triplets){
            if(v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) continue;
            a = max(a, v[0]);
            b = max(b, v[1]);
            c = max(c, v[2]);
        }
        return ((a == target[0] && b == target[1] && c == target[2]) ? true : false);
    }
};
