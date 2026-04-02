class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> vec;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, target);
        return vec;
    }
    void backtrack(auto& nums, int idx, int target){
        if(target < 0) return;
        if(target == 0) { vec.push_back(tmp); return;}

        for(int i = idx; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            backtrack(nums, i, target-nums[i]);
            if(!tmp.empty()) tmp.pop_back();
        }
    } 
};
