class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s, ss;
        unordered_map<int, bool> mp;
        for(int i : nums) mp[i] = true;
        for(int i : nums)
        {
            if(!mp[i-1]) s.insert(i);
            ss.insert(i);
        }
        int mx, k, tmp;
        mx = 0;
        for(int i : s)
        {    
            // cout << i;        
            k = 0;
            tmp = i-1;
            for(int j : ss)
            {
                if(j-tmp == 1) ++k, ++tmp;
                else {mx = max(mx, k), k = 0;}
                // cout << k;
            }
        }
        mx = max(mx, k);
        return mx;
    }
};
// nums=[9,1,4,7,3,-1,0,5,8,-1,6]
// -1  0 1 3 4 5 6 7 8 9
