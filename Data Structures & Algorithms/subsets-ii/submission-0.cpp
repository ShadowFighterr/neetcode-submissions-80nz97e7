class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i < pow(2, n); i++){
            vector<int> v;
            // v.reserve(0);
            for(int j = 0; (1<<j) <= i; j++){
                if((1<<j)&i) v.push_back(nums[j]); 
            }
            s.insert(v);
        }
        for(auto v : s) vec.push_back(v);
        return vec;
    }

};
