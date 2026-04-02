class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int mx = 0;
        while(l < r)
        {
            int x = min(heights[l], heights[r]) * (r-l);
            mx = max(mx, x);
            if(heights[l] <= heights[r]) ++l;
            else --r;
        }
        return mx;
    }
};