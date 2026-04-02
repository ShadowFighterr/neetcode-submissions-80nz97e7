class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            // if(!st.empty())
            // {
                while(!st.empty() && temperatures[i] > st.top().first)
                {
                    v[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({temperatures[i], i});
            // }
            // else st.push({temperatures[i], i});
        }
        return v;
    }
};
