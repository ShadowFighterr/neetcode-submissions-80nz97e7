class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = 1, z = 0;
        for(int x : nums) {if(x == 0) {++z; continue;} cnt*=x;}
        vector<int> v;
        if(z == 1)
        {
            for(int x : nums) 
            {
                if(x == 0) v.push_back(cnt);
                else v.push_back(0);
            }
        }
        else if(z > 1)
        {
            for(int i = 0; i< nums.size(); i++) v.push_back(0);
        }
        else
        {
            for(int x : nums) 
            {
                v.push_back(cnt/x);
            }
        }
        return v;
    }
};
