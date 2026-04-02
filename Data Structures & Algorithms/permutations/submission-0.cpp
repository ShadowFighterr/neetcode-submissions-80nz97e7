class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs({}, nums);
        return res;
    }

    void dfs(vector<int> vec, auto& nums){
        if(vec.size() == nums.size()) {
            res.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(nums[i] != 11)vec.push_back(nums[i]);
            else continue;
            nums[i] = 11;
            dfs(vec, nums);
            nums[i] = x;
            vec.pop_back();
        }
    }
};
