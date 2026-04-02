class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mx = 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < heights.size(); i++)
        {
            int j = i;
            while(!st.empty() && st.top().second > heights[i])
            { 
                mx = max(mx, st.top().second*(i-st.top().first)); 
                j = st.top().first;
                st.pop();
            }
            st.push({j, heights[i]});
        }
        while(!st.empty())
        {
            int y;
            y = st.top().second*(heights.size()-st.top().first);
            mx = max(mx, y);
            st.pop(); 
        }
        return mx;
    }
};
