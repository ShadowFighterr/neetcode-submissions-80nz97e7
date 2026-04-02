class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0; i < pow(2, n); i++){
            vector<int> vec;
            for(int j = 0; (1<<j) <= i; j++){
                if((1<<j)&i)vec.push_back(nums[j]);
            }
            v.push_back(vec);
        }
        return v;
    }
};
