class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n, 0);
        stack<pair<int, int>> st;
        for(int i = 0; i < n; i++)
        {
            if(!st.empty()) 
            {
                if(temperatures[i] > st.top().first)
                {
                    while(!st.empty() && temperatures[i] > st.top().first)
                    {
                        // cout << 1;
                        v[st.top().second] = (i-st.top().second);
                        st.pop();
                    }
                }
                st.push({temperatures[i], i});
            } 
            else st.push({temperatures[i], i}); 
        }
        return v;
    }
};
